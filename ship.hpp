#pragma once

#include <memory>
#include <vector>
#include <string>

#include "cargo.hpp"

class Ship {
public:
  Ship(size_t id, const std::string &name, size_t speed, size_t maxCrew, size_t capacity);

  // adding cargo
  void load(std::shared_ptr<Cargo> cargo);
  // removing cargo
  void unload(Cargo *cargo);
  // listing cargo
  void listCargo() const;

  // getters
  size_t getId() const;
  std::string getName() const;
  size_t getSpeed() const;
  size_t getMaxCrew() const;
  size_t getCapacity() const;
  size_t getCrew() const;

  Ship &operator+=(const size_t num);
  Ship &operator-=(const size_t num);

  void setName(const std::string &name);
  void printData() const;

  // interaction beetwen ships
  void transferCargo(Ship &fromShip, Ship &toShip, Cargo *cargo);

private:
  size_t id_;
  std::string name_;
  size_t speed_;
  size_t maxCrew_;
  size_t capacity_;
  size_t crew_;
  size_t currentCargoWeight_;
  std::vector<std::shared_ptr<Cargo>> cargo_;
};
