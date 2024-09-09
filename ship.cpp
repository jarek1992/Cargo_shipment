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
  if (currentCargoWeight_ + cargoWeight <= capacity_) {
    cargo_.push_back(cargo);
    currentCargoWeight_ += cargoWeight; // updating current cargo weight
  } else {
    std::cout << "cannot load more cargo on the ship, capacity exceeded" << std::endl;
  }
}

void Ship::unload(Cargo *cargo) {
  auto it = std::remove_if(cargo_.begin(), cargo_.end(),
                            [cargo, this](const std::shared_ptr<Cargo> &c) {
                                if (c.get() == cargo) {
                                    currentCargoWeight_ -= c->getAmount(); // update current cargo weight
                                    return true;
                                }
                                return false;
                            });
                            if (it != cargo_.end()) {
                                cargo_.erase(it, cargo_.end());
                                std::cout << "Cargo unloaded successfully" << std::endl;
                            } else {
                            std::cout << "Cargo not found" << std::endl;
                            }
}

void Ship::listCargo() const {
  std::cout << "Cargo on ship: " << std::endl;
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
            << "- capacity: " << capacity_ << "(tons)" << '\n'
            << "- crew: " << crew_ << " people" << '\n';
  std::cout << "------------------------------------" << std::endl;
}

void Ship::transferCargo(Ship &fromShip, Ship &toShip, Cargo *cargo) {
  auto it = std::find_if(
      fromShip.cargo_.begin(), fromShip.cargo_.end(),
      [cargo](const std::shared_ptr<Cargo> &c) { return c.get() == cargo; });

  if (it != fromShip.cargo_.end()) {
    if (toShip.getCapacity() >=
        toShip.currentCargoWeight_ + (*it)->getAmount()) {
      toShip.load(*it);
      fromShip.unload(cargo);
    } else {
      std::cout << "Not enough capacity on the target ship" << std::endl;
    }
  } else {
    std::cout << "Cargo not found on the source ship" << std::endl;
  }
}
