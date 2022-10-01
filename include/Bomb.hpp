#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

#include "../utils/getRndNumber.cpp"
#include "../utils/isEqualPairs.cpp"

namespace utils {
using BombCoord = std::pair<unsigned, unsigned>;
class Bomb {
  std::vector<utils::BombCoord> bombsCoord{};
  const unsigned boardSize;
  const unsigned numOfBomb;

public:
  Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val);
  void setAll();
  void setNewOne(BombCoord coord);
  BombCoord getFreeRandomCoords();
  BombCoord getRandomCoord();
  bool isOccupiedCoord(BombCoord coord);
};

}; // namespace utils

#endif //_BOMB_HPP_