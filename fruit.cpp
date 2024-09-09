#include "fruit.hpp"

Fruit::Fruit(const std::string &name, size_t amount, size_t basePrice, size_t expiryDays)
    : Cargo(name, amount, basePrice)
    , expiryDays_(expiryDays)
    , maxExpiryDays_(expiryDays) 
{}

std::string Fruit::getName() const { 
  return name_; 
}
size_t Fruit::getAmount() const { 
  return amount_; 
}
size_t Fruit::getBasePrice() const { 
  return basePrice_; 
}

// price according to expiry date
size_t Fruit::getPrice() const {
  if (expiryDays_ <= 0) {
    return 0;
  }
  double freshnessFactor = static_cast<double>(expiryDays_) / maxExpiryDays_;
  return static_cast<size_t>(basePrice_ * freshnessFactor * amount_);
}

size_t Fruit::getExpiryDays() const { return expiryDays_; }

Fruit &Fruit::operator--() {
  if (expiryDays_ > 0) {
    --expiryDays_;
  }
  return *this;
}

void Fruit::decreaseExpiryDays() {
  if (expiryDays_ > 0) {
    --expiryDays_;
  }
}