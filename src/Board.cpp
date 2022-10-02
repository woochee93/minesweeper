#include "../include/Board.hpp"

using namespace utils;

Board::Board(const unsigned size_val) : size(size_val){};

void Board::fillBoardWithZero() {
  for (unsigned numOfRow{0}; numOfRow < size; ++numOfRow) {
    pushRowWithZero(numOfRow);
  }
}

void Board::pushRowWithZero(unsigned numOfRow) {
  for (unsigned numOfColumn{}; numOfColumn < size; ++numOfColumn) {
    board.push_back({numOfRow, numOfColumn, '0'});
  }
}

void Board::plantAllBombs(const std::vector<BoardCoord>& allBombs) {
  for (auto& bombCoord : allBombs) {
    auto it = std::find_if(board.begin(), board.end(),
                           [&bombCoord](BoardCoord& boardCoord) {
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

BoardIterator Board::getBoardIteratorWithBomb(const BoardCoord& singleBombCoord) {
  auto it = std::find_if(board.begin(), board.end(),
                         [&singleBombCoord](BoardCoord& boardCoord) {
                           return boardCoord == singleBombCoord;
                         });
  return it;
};
void putNumbersAround(BoardIterator it) {
   //top y = 0
   //bottom y = size -1
   //left x = 0
   //right x = size -1
};
void Board::putNumbers(const std::vector<BoardCoord>& coordsOfAllBombs) {
  for (auto& singleBombCoord : coordsOfAllBombs) {
    getBoardIteratorWithBomb(singleBombCoord);
  }
};

void Board::init(const std::vector<BoardCoord>& coordsOfAllBombs) {
  fillBoardWithZero();
  plantAllBombs(coordsOfAllBombs);
}