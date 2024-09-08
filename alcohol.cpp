#include "alcohol.hpp"

Alcohol(const std::string& name, size_t amount, size_t basePrice, double alcoholPercentage)
    : Cargo(name, amount, basePrice)
    , alcoholPercentage_(alcoholPercentage) 
{}

// implementation of virtual classes from Cargo class
std::string Alcohol::getName() const { 
    return name_; 
}
size_t Alcohol::getAmount() const { 
    return amount_; 
}
size_t Alcohol::getBasePrice() const { 
    return basePrice_; 
}
size_t Alcohol::getPrice() const {
  double alcoholFactor = alcoholPercentage_ / 96.0;
  return static_cast<size_t>(basePrice_ * alcoholFactor * amount_);
}
double getAlcoholPercentage() const { 
    return alcoholPercentage_; 
}