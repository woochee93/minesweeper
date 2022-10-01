#include "../include/Bomb.hpp"

using namespace utils;

Bomb::Bomb(const unsigned boardSize_val, const unsigned numOfBomb_val)
    : boardSize{boardSize_val}, numOfBomb{numOfBomb_val} {};

void utils::Bomb::setOne(BombCoord coord) {
  bombsCoord.push_back(coord);
}

BombCoord Bomb::getRandomCoord() {
  const unsigned lowerBand = 0;
  const unsigned upperBand = boardSize - 1;
  const int randomFirst = getRndNumber<int>(lowerBand, upperBand);
  const int randomSecond = getRndNumber<int>(lowerBand, upperBand);
  return BombCoord {randomFirst, randomSecond};
};

bool Bomb::isOccupiedCoord(BombCoord givenCoord) {
  auto isAlreadyExist = [&givenCoord](BombCoord& bombCoord) {
    return isEqualPairs<BombCoord>(givenCoord, bombCoord);
  };
  auto seekerOfGivenCoord = std::find_if(bombsCoord.begin(), bombsCoord.end(), isAlreadyExist);
  bool isCoordOccupied = seekerOfGivenCoord != bombsCoord.end();
  return isCoordOccupied;
}

BombCoord Bomb::getNotOccupiedRandomCoords() {
  BombCoord newCoord = getRandomCoord();
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

