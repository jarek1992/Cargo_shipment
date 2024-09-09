#include "dryfruit.hpp"

DryFruit::DryFruit(const std::string &name, size_t amount, size_t basePrice, size_t expiryDate)
    : Fruit(name, amount, basePrice, expiryDate)
    , useCounter_(0) 
{}

// overwriting getPrice()
size_t DryFruit::getPrice() const { 
    return 3 * getBasePrice() * getAmount(); 
}
// overwriting getName()
std::string DryFruit::getName() const { 
    return "Dry" + Fruit::getName(); 
}
// overwriting operator--
DryFruit &DryFruit::operator--() {
  if (++useCounter_ % 10 == 0) {
    decreaseExpiryDays();
  }
  return *this;
}
