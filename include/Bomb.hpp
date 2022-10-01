#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

#include "../utils/getRndNumber.cpp"
#include "../utils/isEqualPairs.cpp"

namespace utils {
using BombCoords = std::pair<unsigned, unsigned>;
class Bomb {
  std::vector<utils::BombCoords> bombsCoord{};
  const unsigned boardSize;
  const unsigned numOfBomb;

public:
  Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val);
  void setAll();
  void setNewOne(BombCoords coord);
  BombCoords getFreeRandomCoords();
  BombCoords getRandomCoord();
  bool isOccupiedCoord(BombCoords coord);
};

}; // namespace utils

#endif //_BOMB_HPP_