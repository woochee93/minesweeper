#include "../include/Bomb.hpp"

using namespace utils;

Bomb::Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val)
    : boardSize{boardSize_val}, numOfBomb{numOfBomb_val} {};

void utils::Bomb::setOne(Field coord) { bombFields.push_back(coord); }

Field Bomb::getRandomField() {
  const unsigned lowerBand = 0;
  const unsigned upperBand = boardSize - 1;
  const unsigned randomFirst = getRndNumber<unsigned>(lowerBand, upperBand);
  const unsigned randomSecond = getRndNumber<unsigned>(lowerBand, upperBand);
  char value = 'B';
  return Field{randomFirst, randomSecond, value};
};

bool Bomb::isOccupiedField(Field givenCoord) {
  auto seekerOfGivenCoord =
      std::find(bombFields.begin(), bombFields.end(), givenCoord);
  bool isCoordOccupied = seekerOfGivenCoord != bombFields.end();
  return isCoordOccupied;
}

Field Bomb::getNotOccupiedRandomField() {
  Field newCoord = getRandomField();
  while (isOccupiedField(newCoord)) {
    newCoord = getRandomField();
  }
  return newCoord;
}

void Bomb::setAll() {
  for (unsigned i{0}; i < numOfBomb; i++) {
    setOne(getNotOccupiedRandomField());
  }
};

std::vector<Field> Bomb::getBombFields() { return bombFields; }