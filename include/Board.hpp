#ifndef  _BOARD_HPP_
#define _BOARD_HPP_

#include <vector>
#include <iostream>
#include <algorithm>

#include "Field.hpp"
namespace utils {
class Board {
  const unsigned size;
  std::vector<Field> board{};
  void pushNewRowWithZeros(unsigned numOfRow);
  void fillWithZeros();
  void plantAllBombs(const std::vector<Field>& coordsOfAllBombs);
  void putNumbers(const std::vector<Field>& coordsOfAllBombs);
  Field& getSameField(const Field& singleBombCoord);
  public:
  Board(const unsigned size_val);
  void init(const std::vector<Field>& coordsOfAllBombs);
  void printBoard();

};
}
#endif // _BOARD_HPP_