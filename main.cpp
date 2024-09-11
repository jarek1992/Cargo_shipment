#include "dryfruit.hpp"
#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "ship.hpp"
#include "weapon.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main() {

  //setting up the ship no.1
  Ship ship1(196, "Flying Dutch", 30, 50, 100000); //id, name, speed, max_crew, capacity
  Ship ship2(598, "Black Pearl", 120, 34, 500);

  //adding crew members
  // ship2 += 14;

  //ships data
  ship1.printData();
  ship2.printData();

  std::cout << std::endl;

  //declaring cargo stuff
  std::shared_ptr<Cargo> apples = std::make_shared<Fruit>("Apples", 10000, 1, 30); //name, amount, basePrice, expiryDays
  std::shared_ptr<Cargo> rum = std::make_shared<Alcohol>("Rum", 250, 10, 40.0); //name, amount, basePrice, alcoholPercentage
  std::shared_ptr<Cargo> ferrari = std::make_shared<Item>("Golden Armour", 1, 1000000, Rarity::Almost_Unavailable); //name, amount, basePrice, rarity
  std::shared_ptr<Cargo> guns = std::make_shared<Weapon>("Sword", 200, 2, 25, Rarity::Common); //name, amount, basePrice, damage, rarity
  std::shared_ptr<Cargo> dryFruits = std::make_shared<DryFruit>("Carrots", 500, 2, 60); // name, amount, basePrice, expiryDays)

  //loading cargo on the ship1
  std::cout << "Ship ID-" << ship1.getId() << " \"" << ship1.getName() << "\":" << std::endl;
  ship1.load(apples);
  ship1.load(rum);
  ship1.load(ferrari);
  
  //loading cargo on the ship2
  std::cout << "Ship ID-" << ship2.getId() << " \"" << ship2.getName() << "\":" << std::endl;
  ship2.load(guns);
  ship2.load(dryFruits);

  //list of cargo on the ship1
  std::cout << "List of cargo stuff loaded on the ship1:" << std::endl;
  ship1.listCargo();
  std::cout << std::endl;

  //simulation of time for apples to expire
  std::cout << "Counting down the days for apples to expire: " << std::endl;
  for (int i = 0; i < 30; ++i) {
    --(*std::static_pointer_cast<Fruit>(apples));
    if (i % 5 == 0 || i == 29) {
      std::cout << "Day " << i + 1 << ":" << std::endl;
      ship1.listCargo();
    }
  }

  //unloading apples from ship1
  std::cout << "Unloading apples from the ship ID-" << ship1.getId() << std::endl;
  ship1.unload(apples.get());
  ship1.listCargo();

  //attempt of unloading non-existing stuff from the ship1
  std::cout << "Unload cargo from the ship:" << ship1.getId() << std::endl;
  ship1.unload(apples.get());
  ship1.listCargo();
  std::cout << std::endl;

  //transfer of cargo between ship1 and ship2
  std::cout << "Transfering rum from ship ID-" << ship1.getId() << " \"" << ship1.getName() << " \"" 
            << " to ship ID-"<< ship2.getId() << " \"" << ship2.getName() << " \":" << std::endl;
  ship1.transferCargo(ship1, ship2, rum.get());
 
  
  ship1.listCargo();
  std::cout << std::endl;
  ship2.listCargo();
  std::cout << std::endl;

  //adding subtracting some crew members 
  ship2 += 6;
  ship2 -= 3;

  //testing class DryFruit
  std::cout << dryFruits->getName() << ": ";
  std::cout << "original price: " << dryFruits->getPrice() << std::endl;

  std::cout << "simulating dry fruit usage on ship " << ship1.getName() << ": " << std::endl;
  for (int i = 0; i < 20; ++i) {
    --(*std::static_pointer_cast<DryFruit>(dryFruits));
    if (i % 5 == 0 || i == 19) {
      std::cout << "after " << i + 1 << " uses, expiry date is: " << std::static_pointer_cast<Fruit>(dryFruits)->getExpiryDays() << std::endl;
    }
  }
  return 0;
}