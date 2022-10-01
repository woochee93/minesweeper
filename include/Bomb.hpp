#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <algorithm>
#include <functional>
#include <random>
#include <utility>
#include <vector>

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
  BombCoords setNewBombInFreeCoords ();
  BombCoords generateRandomBombCoord();
  bool isFree(BombCoords cord);
};

}; // namespace utils

#endif //_BOMB_HPP_