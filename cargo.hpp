#pragma once

#include <string>

// enum deteminating rarity level of item
enum class Rarity { 
  Common, 
  Rare, 
  Very_Rare, 
  Almost_Unavailable 
};

// base class
class Cargo {
public:
  Cargo(const std::string &name, size_t amount, size_t basePrice);
  virtual ~Cargo() = default;

  // pure virtual methods
  virtual size_t getPrice() const = 0;
  virtual std::string getName() const = 0;
  virtual size_t getAmount() const = 0;
  virtual size_t getBasePrice() const = 0;

  virtual void setAmount(size_t amount) = 0;
  virtual void setBasePrice(size_t basePrice) = 0;

protected:
  std::string name_;
  size_t amount_;
  size_t basePrice_;
};