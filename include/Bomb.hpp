#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <vector>
#include <utility>
#include <random>
#include <algorithm>
#include <functional>


namespace utils {
using BombCoords = std::pair<unsigned, unsigned>;
class Bomb {
  std::vector<utils::BombCoords> bombsCoord{};
  const unsigned size;

public:
Bomb(const unsigned boardSize=3):size{boardSize}{}
  void setBunchOfBombs();
  void setBomb(unsigned x, unsigned y);
  BombCoords generateRandomBombCoord();
  bool isFree(BombCoords cord);
};

}; // namespace utils

#endif //_BOMB_HPP_