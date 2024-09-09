#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string &name, size_t amount, size_t price, int damage, Rarity rarity)
    : Item(name, amount, price, rarity)
    , damage_(damage) 
{
  if (damage_ < 0) {
    throw std::invalid_argument("Damage cannot be negative");
  }
}
int Weapon::getDamage() const { 
    return damage_; 
}
