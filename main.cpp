#include <iostream>
#include <string>
#include <vector> 
#include <memory>
#include <algorithm>
#include "cargo.hpp"
#include "fruit.hpp"
#include "alcohol.hpp"

class Item : public Cargo {
public:
  Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice)
    , rarity_(rarity)
  {}

  //implementation of virtual classes from Cargo class
  std::string getName() const override { return name_; }
  size_t getAmount() const override { return amount_; }
  size_t getBasePrice() const override { return basePrice_; }
  size_t getPrice() const override {
    double multiplier = rarityMultiplier(rarity_);
    return static_cast<size_t>(basePrice_ * multiplier * amount_);
  }

  Rarity getRarity() const { return rarity_; }
  
private:
  Rarity rarity_;

  //additional function helping to change the price according to rarity of item
  double rarityMultiplier(Rarity rarity) const {
    switch (rarity) {
      case Rarity::Common : {
        return 1.0;
      }
      case Rarity::Rare : {
        return 1.5;
      }
      case Rarity::Very_Rare : {
        return 2.0;
      }
      case Rarity::Almost_Unavailable : {
        return 3.0;
      }
      default: {
        return 1.0;
      }
    }
  }
 
};

class Weapon : public Item {
public:
  Weapon(const std::string&name, size_t amount, size_t price, int damage, Rarity rarity)
    : Item(name, amount, price, rarity)
    , damage_(damage)
  {
    if(damage_ < 0) {
      throw std::invalid_argument("Damage cannot be negative");
    }
  }

  int getDamage() const { return damage_; }

private:
  int damage_;
};

class DryFruit : public Fruit {
public:
  DryFruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDays)
    : Fruit(name, amount, basePrice, expiryDays)
    , useCounter_(0)
  {}

  //overwriting getPrice()
  size_t getPrice() const override {
    return 3 * getBasePrice() * getAmount();
  }
  //overwriting getName()
  std::string getName() const override {
    return name_ + "(Dry)";
  }
  //overwriting operator--
  DryFruit& operator--() {
    if(++useCounter_ % 10 == 0) {
      decreaseExpiryDays();
    }
    return *this;
  }

private:
  mutable size_t useCounter_; // counter for operator--
}; 

class Ship {
public:
  Ship(size_t id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
    , crew_(0)
    , currentCargoWeight_(0)
  {}


//adding cargo
  void load(std::shared_ptr<Cargo> cargo) {
    size_t cargoWeight = cargo->getAmount();
    if(currentCargoWeight_ + cargoWeight <= capacity_) {
      cargo_.push_back(cargo);
      currentCargoWeight_ += cargoWeight; // updating current cargo weight
    } else {
      std::cout << "cannot load more cargo on the ship, capacity exceeded" << std::endl;
    }
  }

//removing cargo
void unload(Cargo* cargo) {
  auto it = std::remove_if(cargo_.begin(), cargo_.end(), 
    [cargo, this](const std::shared_ptr<Cargo>& c) {
      if(c.get() == cargo) {
        currentCargoWeight_ -= c->getAmount(); // update current cargo weight
        return true;
      }
      return false;
    });
  if(it != cargo_.end()) {
    cargo_.erase(it, cargo_.end());
    std::cout << "Cargo unloaded successfully" << std::endl;
  } else {
    std::cout << "Cargo not found" << std::endl;
  }
}

//listing cargo 
  void listCargo() const {
    std::cout << "Cargo on ship: " << std::endl;
    for(const auto& cargo : cargo_) {
      std::cout << "- " << cargo->getName() 
                << " |amount: " << cargo->getAmount() 
                << " |price: " << cargo->getPrice() << "$" << std::endl;
    }
  }



//getters
  size_t getId() const { return id_; }
  std::string getName() const { return name_; }
  size_t getSpeed() const { return speed_; }
  size_t getMaxCrew() const { return maxCrew_; }
  size_t getCapacity() const { return capacity_; }
  size_t getCrew() const { return crew_; }
 
  Ship& operator+=(const size_t num) {
    if(crew_ + num <= maxCrew_) {
      crew_ += num;
    } else {
      std::cout << "reached maxCrew amount, cannot add more" << std::endl;
    }
    return *this;
  }
  Ship& operator-=(const size_t num) {
    if(crew_ >= num) {
      crew_ -= num;
    } else {
      std::cout << "not enough crew members, can not delete crew" << std::endl;
    }
    return *this;
  }

  void setName(const std::string& name) { name_ = name; }

  void printData() const {
    std::cout << "Ship ID-" << id_ << ":" <<  '\n'
              << "- name: " << name_ << '\n'
              << "- speed: " << speed_ << "knts" << '\n'
              << "- max_crew: " << maxCrew_ << " people" << '\n'
              << "- capacity: " << capacity_ << "(tons)" << '\n'
              << "- crew: " << crew_ << " people" << '\n';
    std::cout << "------------------------------------" << std::endl;
  }

  // interaction beetwen ships
  void transferCargo(Ship& fromShip, Ship& toShip, Cargo* cargo) {
    auto it = std::find_if(fromShip.cargo_.begin(), fromShip.cargo_.end(), 
    [cargo](const std::shared_ptr<Cargo>& c) {return c.get() == cargo; });

    if(it != fromShip.cargo_.end()) {
      if(toShip.getCapacity() >= toShip.currentCargoWeight_ + (*it)->getAmount()) {
        toShip.load(*it);
        fromShip.unload(cargo);
      } else {
        std::cout << "Not enough capacity on the target ship" << std::endl;
      }
    } else {
      std::cout << "Cargo not found on the source ship" << std::endl;
    }
  }

private:
  size_t id_;
  std::string name_;
  size_t speed_;
  size_t maxCrew_;
  size_t capacity_;
  size_t crew_;
  size_t currentCargoWeight_;
  std::vector<std::shared_ptr<Cargo>> cargo_;
};

int main() {

  //setting up the ship no.1
  Ship ship1(1, "Black Pearl", 30, 50, 75);
  ship1 += 45; //adding crew members
  ship1.printData();
  
  std::cout << std::endl;

  //declaring cargo stuff
  std::shared_ptr<Cargo> apples = std::make_shared<Fruit>("Apples", 10000, 1, 30);
  std::shared_ptr<Cargo> vodka = std::make_shared<Alcohol>("Vodka", 250, 10, 40.0);
  std::shared_ptr<Cargo> ferrari_STO = std::make_shared<Item>("Ferrari STO", 1, 1000000, Rarity::Almost_Unavailable);

  //load cargo on the ship
  ship1.load(apples);
  ship1.load(vodka);
  ship1.load(ferrari_STO);

  //list of cargo on the ship
  std::cout << "List of cargo stuff loaded on the ship:" << std::endl;
  ship1.listCargo();
  std::cout << std::endl;

  //simulation of expiration for apples
  std::cout << "Counting down the days for apples to expire: " << std::endl;
  for(int i = 0; i < 30; ++i) {
    --(*std::static_pointer_cast<Fruit>(apples));
    if(i % 5 == 0 || i == 29) {
      std::cout << "Day " << i +1 << ":" << std::endl;
      ship1.listCargo();
      std::cout << std::endl;
    }
  }

  std::cout << "Unloading apples from the ship:" << std::endl;
  ship1.unload(apples.get());
  ship1.listCargo();
  std::cout << std::endl;

  //attempt of unloading non-existing stuff from the ship
  std::cout << "Unload cargo from the ship:" << std::endl;
  ship1.unload(apples.get());
  ship1.listCargo();
  std::cout << std::endl;

  Ship ship2(2, "Flying Dutchman", 120, 47, 50);
  ship2 += 39;
  ship2.printData();

  return 0;
}