#include "item.hpp"

Item::Item(const std::string &name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice)
    , rarity_(rarity) 
{}

// implementation of virtual classes from Cargo class
std::string Item::getName() const { 
  return name_; 
}
size_t Item::getAmount() const { 
  return amount_; 
}
size_t Item::getBasePrice() const { 
  return basePrice_; 
}
size_t Item::getPrice() const {
  double multiplier = rarityMultiplier(rarity_);
  return static_cast<size_t>(basePrice_ * multiplier * amount_);
}
Rarity Item::getRarity() const { 
  return rarity_; 
}

// additional function helping to change the price according to rarity of item
double Item::rarityMultiplier(Rarity rarity) const {
  switch (rarity) {
  case Rarity::Common: {
    return 1.0;
  }
  case Rarity::Rare: {
    return 1.5;
  }
  case Rarity::Very_Rare: {
    return 2.0;
  }
  case Rarity::Almost_Unavailable: {
    return 3.0;
  }
  default: {
    return 1.0;
  }
  }
}