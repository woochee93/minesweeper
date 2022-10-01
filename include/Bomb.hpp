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
  const unsigned size;
  const unsigned bombNum;

public:
  Bomb(const unsigned boardSize, const unsigned numOfBomb);
  void setBunchOfBombs();
  void setBomb(unsigned x, unsigned y);
  BombCoords setNewBombInFreeCoords();
  BombCoords getRandomBombCoord();
  bool isFree(BombCoords coord);
};

}; // namespace utils

#endif //_BOMB_HPP_