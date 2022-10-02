#ifndef _MINE_HPP_
#define _MINE_HPP_

#include "Board.hpp"
#include "Bomb.hpp"
#include <memory>

namespace utils {

class Minesweeper {
  std::shared_ptr<Bomb> bomb;
  std::shared_ptr<Board> board;

public:
  Minesweeper(const unsigned size = 3, const unsigned numOfBomb = 3);
  void initGame();
  std::shared_ptr<Bomb> getBomb();
  std::shared_ptr<Board> getBoard();

};
} // namespace utils

#endif // _MINE_HPP_