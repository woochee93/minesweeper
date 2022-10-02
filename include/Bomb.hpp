#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

#include "BoardCoord.hpp"
#include "../utils/getRndNumber.cpp"

namespace utils {
class Bomb {
  std::vector<BoardCoord> bombsCoord{};
  const unsigned boardSize;
  const unsigned numOfBomb;

public:
  Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val);
  void setAll();
  void setOne(BoardCoord coord);
  BoardCoord getNotOccupiedRandomCoords();
  BoardCoord getRandomCoord();
  bool isOccupiedCoord(BoardCoord coord);
};

}; // namespace utils

#endif //_BOMB_HPP_