#include "weapon.hpp"
#include <stdexcept>

Weapon::Weapon(const std::string &name, size_t amount, size_t basePrice, int damage, Rarity rarity)
    : Item(name, amount, basePrice, rarity)
    , damage_(damage) 
{
  if (damage_ < 0) {
    throw std::invalid_argument("Damage cannot be negative");
  }
}

void Weapon::setAmount(size_t amount) {
  Item::setAmount(amount);
}
void Weapon::setBasePrice(size_t basePrice) {
  Item::setBasePrice(basePrice);
}
int Weapon::getDamage() const { 
    return damage_; 
}

