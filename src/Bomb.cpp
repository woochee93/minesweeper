#include "../include/Bomb.hpp"

using namespace utils;

Bomb::Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val)
    : boardSize{boardSize_val}, numOfBomb{numOfBomb_val} {};

void utils::Bomb::setNewOne(BombCoords coord) {
  bombsCoord.push_back(coord);
}

BombCoords Bomb::getRandomCoord() {
  const unsigned lowerBand = 0;
  const unsigned upperBand = boardSize - 1;
  auto getRandomInRange = [&lowerBand, &upperBand]() {
    return getRndNumber<int>(lowerBand, upperBand);
  };
  return BombCoords{getRandomInRange(), getRandomInRange()};
};

bool Bomb::isOccupiedCoord(BombCoords givenCoord) {
  auto isAlreadyExist = [&givenCoord](BombCoords& bombCoord) {
    return isEqualPairs<BombCoords>(givenCoord, bombCoord);
  };
  auto it = std::find_if(bombsCoord.begin(), bombsCoord.end(), isAlreadyExist);
  bool isOccupied = it != bombsCoord.end();
  return isOccupied;
}

BombCoords Bomb::getFreeRandomCoords() {
  BombCoords newCoord = getRandomCoord();
  while (isOccupiedCoord(newCoord)) {
    newCoord = getRandomCoord();
  }
  return newCoord;
}

void Bomb::setAll() {
  for (unsigned i{0}; i < numOfBomb; i++) {
    setNewOne(getFreeRandomCoords());
  }
};

