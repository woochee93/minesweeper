#ifndef _MINE_HPP_
#define _MINE_HPP_

#include "Bomb.hpp"
#include <memory>

namespace utils {

class Minesweeper {
  const unsigned boardSize;
  std::shared_ptr<Bomb> bomb;

public:
  Minesweeper(const unsigned size = 3);
  std::shared_ptr<Bomb> getBomb();
};
} // namespace utils

#endif // _MINE_HPP_