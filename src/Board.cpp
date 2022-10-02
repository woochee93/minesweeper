#include "../include/Board.hpp"

using namespace utils;

Board::Board(const unsigned size_val) : size(size_val){};

void Board::fillAllWithZeros() {
  for (unsigned numOfRow{0}; numOfRow < size; ++numOfRow) {
    pushNewRowWithZeros(numOfRow);
  }
}

void Board::pushNewRowWithZeros(unsigned numOfRow) {
  for (unsigned numOfColumn{}; numOfColumn < size; ++numOfColumn) {
    board.push_back({numOfRow, numOfColumn, '0'});
  }
}

void Board::plantAllBombs(const std::vector<Field>& allBombs) {
  for (auto& bombCoord : allBombs) {
    auto it = std::find_if(board.begin(), board.end(),
                           [&bombCoord](Field& boardCoord) {
                             return boardCoord == bombCoord;
                           });
    it->value = 'B';
  }
};

void Board::printBoard() {
  for (unsigned i{0}; i < size * size; ++i) {
    std::cout << board.at(i).value;
    if ((i % size) == size - 1) {
      std::cout << std::endl;
    }
  }
};

BoardIterator Board::getBoardIteratorWithBomb(const Field& singleBombCoord) {
  auto it = std::find_if(board.begin(), board.end(),
                         [&singleBombCoord](Field& boardCoord) {
                           return boardCoord == singleBombCoord;
                         });
  return it;
};
// void putNumbersAround(BoardIterator it) {
//    //top y = 0
//    //bottom y = size -1
//    //left x = 0
//    //right x = size -1
// };
void Board::putNumbers(const std::vector<Field>& coordsOfAllBombs) {
  for (auto& singleBombCoord : coordsOfAllBombs) {
    getBoardIteratorWithBomb(singleBombCoord);
  }
};

void Board::init(const std::vector<Field>& coordsOfAllBombs) {
  fillAllWithZeros();
  plantAllBombs(coordsOfAllBombs);
}