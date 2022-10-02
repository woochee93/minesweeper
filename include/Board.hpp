#ifndef  _BOARD_HPP_
#define _BOARD_HPP_

#include <vector>
#include <iostream>
#include <algorithm>

#include "BoardCoord.hpp"
namespace utils {
  using BoardIterator = std::vector<utils::BoardCoord>::iterator;
class Board {
  const unsigned size;
  std::vector<BoardCoord> board{};
  void pushRowWithZero(unsigned numOfRow);
  void fillBoardWithZero();
  void plantAllBombs(const std::vector<BoardCoord>& coordsOfAllBombs);
  void putNumbers(const std::vector<BoardCoord>& coordsOfAllBombs);
  BoardIterator Board::getBoardIteratorWithBomb(const BoardCoord& singleBombCoord);
  public:
  Board(const unsigned size_val);
  void init(const std::vector<BoardCoord>& coordsOfAllBombs);
  void printBoard();

};
}
#endif // _BOARD_HPP_