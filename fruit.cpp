#include "fruit.hpp"

Fruit::Fruit(const std::string &name, size_t amount, size_t basePrice, size_t expiryDays)
    : Cargo(name, amount, basePrice)
    , expiryDays_(expiryDays)
    , maxExpiryDays_(expiryDays) 
{}

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