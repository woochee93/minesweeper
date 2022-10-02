#include "../include/Bomb.hpp"

using namespace utils;

Bomb::Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val)
    : boardSize{boardSize_val}, numOfBomb{numOfBomb_val} {};

void utils::Bomb::setOne(Field coord) {
  bombsCoord.push_back(coord);
}

Field Bomb::getRandomCoord() {
  const unsigned lowerBand = 0;
  const unsigned upperBand = boardSize - 1;
  const unsigned randomFirst = getRndNumber<unsigned>(lowerBand, upperBand);
  const unsigned randomSecond = getRndNumber<unsigned>(lowerBand, upperBand);
  char value{'B'};
  return Field {randomFirst, randomSecond,value};
};

bool Bomb::isOccupiedCoord(Field givenCoord) {
  auto isAlreadyExist = [&givenCoord](Field& bombCoord) {
    return givenCoord == bombCoord;
  };
  auto seekerOfGivenCoord = std::find_if(bombsCoord.begin(), bombsCoord.end(), isAlreadyExist);
  bool isCoordOccupied = seekerOfGivenCoord != bombsCoord.end();
  return isCoordOccupied;
}

Field Bomb::getNotOccupiedRandomCoords() {
  Field newCoord = getRandomCoord();
  while (isOccupiedCoord(newCoord)) {
    newCoord = getRandomCoord();
  }
  return newCoord;
}

void Bomb::setAll() {
  for (unsigned i{0}; i < numOfBomb; i++) {
    setOne(getNotOccupiedRandomCoords());
  }
};


std::vector<Field> Bomb::getBombsCord(){
    return bombsCoord;
  }