#pragma once

#include "item.hpp"

class Weapon : public Item {
public:
  Weapon(const std::string& name, size_t amount, size_t price, int damage, Rarity rarity);

  int getDamage() const;

private:
  int damage_;
};