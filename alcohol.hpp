#pragma once

#include "cargo.hpp"

class Alcohol : public Cargo {
public:
  Alcohol(const std::string& name, size_t amount, size_t basePrice, double alcoholPercentage);
  std::string getName() const override;
  size_t getAmount() const override;
  size_t getBasePrice() const override;
  size_t getPrice() const override;

  double getAlcoholPercentage() const;

private:
  double alcoholPercentage_;
};