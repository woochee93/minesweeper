#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

#include "Field.hpp"
#include "../utils/getRndNumber.cpp"

namespace utils {
class Bomb {
  std::vector<Field> bombFields{};
  const unsigned boardSize;
  const unsigned numOfBomb;

public:
  Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val);
  void setAll();
  void setOne(Field coord);
  Field getNotOccupiedRandomField();
  Field getRandomField();
  bool isOccupiedField(Field coord);
  std::vector<Field> getBombFields();
};
}; // namespace utils

#endif //_BOMB_HPP_