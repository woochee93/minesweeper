#ifndef  _BOARD_HPP_
#define _BOARD_HPP_

#include <vector>
#include <iostream>
#include <algorithm>

#include "Field.hpp"
namespace utils {
  using BoardIterator = std::vector<utils::Field>::iterator;
class Board {
  const unsigned size;
  std::vector<Field> board{};
  void pushNewRowWithZeros(unsigned numOfRow);
  void fillAllWithZeros();
  void plantAllBombs(const std::vector<Field>& coordsOfAllBombs);
  void putNumbers(const std::vector<Field>& coordsOfAllBombs);
  BoardIterator getBoardIteratorWithBomb(const Field& singleBombCoord);
  public:
  Board(const unsigned size_val);
  void init(const std::vector<Field>& coordsOfAllBombs);
  void printBoard();

};
}
#endif // _BOARD_HPP_