#include "../include/Board.hpp"

using namespace utils;

Board::Board(const unsigned size_val) : size(size_val){};

void Board::fillWithZeros() {
  for (unsigned numOfRow{0}; numOfRow < size; ++numOfRow) {
    pushNewRowWithZeros(numOfRow);
  }
}

void Board::pushNewRowWithZeros(unsigned numOfRow) {
  for (unsigned numOfColumn{}; numOfColumn < size; ++numOfColumn) {
    board.push_back({numOfRow, numOfColumn, '0'});
  }
}

void Board::plantAllBombs(const std::vector<Field>& allBombFields) {
  for (auto& bombField : allBombFields) {
    getSameField(bombField).value = bombField.value;
  }
};

void Board::print() {
  for (unsigned i{0}; i < size * size; ++i) {
    std::cout << board.at(i).value;
    const bool isLastInRow = (i % size) == size - 1;
    if (isLastInRow) {
      std::cout << std::endl;
    }
  }
};

Field& Board::getSameField(const Field& wantedField) {
  auto sameFieldSeeker = std::find(board.begin(), board.end(), wantedField);
  return *sameFieldSeeker;
};
// void putNumbersAround(BoardIterator it) {
//    //top y = 0
//    //bottom y = size -1
//    //left x = 0
//    //right x = size -1
// };
void Board::putNumbers(const std::vector<Field>& coordsOfAllBombs) {
  for (auto& singleBombCoord : coordsOfAllBombs) {
    getSameField(singleBombCoord);
  }
};

void Board::init(const std::vector<Field>& coordsOfAllBombs) {
  fillWithZeros();
  plantAllBombs(coordsOfAllBombs);
}