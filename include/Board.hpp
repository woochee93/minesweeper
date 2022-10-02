#ifndef  _BOARD_HPP_
#define _BOARD_HPP_

#include <vector>

#include "BoardCoord.hpp"
namespace utils {
class Board {
  const unsigned size;
  std::vector<BoardCoord> board{};
  public:
  Board(const unsigned size_val);
};
}
#endif // _BOARD_HPP_