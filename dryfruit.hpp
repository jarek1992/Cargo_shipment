#pragma once

#include "fruit.hpp"

class DryFruit : public Fruit {
public:
  DryFruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDays);

  //overwriting getPrice()
  size_t getPrice() const override;
  //overwriting getName()
  std::string getName() const override;
  //overwriting operator--
  DryFruit& operator--();

private:
  mutable size_t useCounter_; // counter for operator--
}; 