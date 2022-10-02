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
  std::vector<Field> bombsCoord{};
  const unsigned boardSize;
  const unsigned numOfBomb;

public:
  Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val);
  void setAll();
  void setOne(Field coord);
  Field getNotOccupiedRandomCoords();
  Field getRandomCoord();
  bool isOccupiedCoord(Field coord);
  std::vector<Field> getBombsCord();

};

}; // namespace utils

#endif //_BOMB_HPP_