#include "ship.hpp"
#include <algorithm>
#include <iostream>

Ship::Ship(size_t id, const std::string &name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
    , crew_(0)
    , currentCargoWeight_(0) 
{}

void Ship::load(std::shared_ptr<Cargo> cargo) {
  size_t cargoWeight = cargo->getAmount();

  std::cout << " attempting to load cargo: " << cargo->getName() << std::endl;
  std::cout << " cargo amount: " << cargo->getAmount() << std::endl;
  std::cout << " current cargo weight: " << currentCargoWeight_ << std::endl;
  std::cout << " ship capacity: " << capacity_ << std::endl;

  if (currentCargoWeight_ + cargoWeight <= capacity_) {
    cargo_.push_back(cargo);
    currentCargoWeight_ += cargoWeight; // updating current cargo weight
  } else {
    std::cout << "!cannot load" << cargo->getName() << " cargo on the ship, capacity exceeded" << std::endl;
  }
}

void Ship::unload(Cargo *cargo) {
  std::cout << " attempting to unload cargo: " << cargo->getName() << std::endl;
  std::cout << " current cargo weight: " << currentCargoWeight_ << std::endl;
  std::cout << std::endl;

  auto it = std::find_if(cargo_.begin(), cargo_.end(),
                            [cargo](const std::shared_ptr<Cargo> &c) {
                                    return c.get() == cargo;
                            });
  if (it != cargo_.end()) {
    size_t amount = (*it)->getAmount();
    currentCargoWeight_ -= amount; //update current cargo weight
    cargo_.erase(it); // remove the cargo
    std::cout << "Cargo unloaded successfully" << std::endl;
  } else {
    std::cout << "Cargo not found" << std::endl;
  }

  std::cout << "Remaining cargo weight: " << currentCargoWeight_ << std::endl;
}

void Ship::listCargo() const {
  std::cout << "Cargo on ship ID-" << id_ << std::endl;
  for (const auto &cargo : cargo_) {
    std::cout << "- " << cargo->getName() 
            << " |amount: " << cargo->getAmount()
            << " |price: " << cargo->getPrice() 
            << "$" << std::endl;
  }
}

size_t Ship::getId() const { 
    return id_; 
}
std::string Ship::getName() const { 
    return name_; 
}
size_t Ship::getSpeed() const { 
    return speed_; 
}
size_t Ship::getMaxCrew() const { 
    return maxCrew_; 
}
size_t Ship::getCapacity() const { 
    return capacity_; 
}
size_t Ship::getCrew() const { 
    return crew_; 
}

Ship &Ship::operator+=(const size_t num) {
  if (crew_ + num <= maxCrew_) {
    crew_ += num;
  } else {
    std::cout << "reached maxCrew amount, cannot add more" << std::endl;
  }
  return *this;
}

Ship &Ship::operator-=(const size_t num) {
  if (crew_ >= num) {
    crew_ -= num;
  } else {
    std::cout << "not enough crew members, can not delete crew" << std::endl;
  }
  return *this;
}

void Ship::setName(const std::string &name) { 
    name_ = name; 
}

void Ship::printData() const {
  std::cout << "Ship ID-" << id_ << ":" << '\n'
            << "- name: " << name_ << '\n'
            << "- speed: " << speed_ << "knts" << '\n'
            << "- max_crew: " << maxCrew_ << " people" << '\n'
            << "- capacity: " << capacity_ << " kg" << '\n'
            << "- crew: " << crew_ << " people" << '\n';
  std::cout << "------------------------------------" << std::endl;
}

void Ship::transferCargo(Ship &fromShip, Ship &toShip, Cargo *cargo) {

  std::cout << " attempting to transfer cargo: " << cargo->getName() << std::endl;
  std::cout << " source ship current cargo weight: " << fromShip.currentCargoWeight_ << std::endl;
  std::cout << " destination ship capacity: " << toShip.capacity_ << std::endl;
  std::cout << " destination ship current cargo weight: " << toShip.currentCargoWeight_ << std::endl;

  auto it = std::find_if (fromShip.cargo_.begin(), fromShip.cargo_.end(),
                            [cargo](const std::shared_ptr<Cargo> &c) { 
                                return c.get() == cargo; 
                            });

  if (it != fromShip.cargo_.end()) {
    auto cargoToTransfer = *it;
    size_t cargoAmount = cargoToTransfer->getAmount();
    if (toShip.getCapacity() >= toShip.currentCargoWeight_ + cargoAmount) {
      toShip.load(cargoToTransfer);
      fromShip.unload(cargo);
    } else {
      std::cout << "Not enough capacity on the target ship" << std::endl;
    }
  } else {
    std::cout << "Cargo not found on the source ship" << std::endl;
  }
}
