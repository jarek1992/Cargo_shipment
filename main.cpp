#include <iostream>
#include <string>
#include <vector> 
#include <memory>
#include <algorithm>
#include "cargo.hpp"
#include "fruit.hpp"
#include "alcohol.hpp"
#include "item.hpp"
#include "weapon.hpp"
#include "ship.hpp"

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