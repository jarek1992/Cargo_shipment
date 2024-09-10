#pragma once

#include "item.hpp"

class Weapon : public Item {
public:
  Weapon(const std::string& name, size_t amount, size_t basePrice, int damage, Rarity rarity);

  void setAmount(size_t amount) override;
  void setBasePrice(size_t price) override;

  int getDamage() const;

private:
  int damage_;
};