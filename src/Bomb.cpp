#include "../include/Bomb.hpp"

using namespace utils;

Bomb::Bomb(const unsigned boardSize, const unsigned numOfBomb)
    : size{boardSize}, bombNum{numOfBomb} {};

void utils::Bomb::setBomb(unsigned x, unsigned y) {
  bombsCoord.push_back(utils::BombCoords(x, y));
}

BombCoords Bomb::getRandomBombCoord() {
  const unsigned lowerBand = 0;
  const unsigned upperBand = size - 1;
  auto getRandomInRange = [&lowerBand, &upperBand]() {
    return getRndNumber<int>(lowerBand, upperBand);
  };
  return BombCoords{getRandomInRange(), getRandomInRange()};
};

BombCoords Bomb::setNewBombInFreeCoords() {
  BombCoords newBomb = getRandomBombCoord();
  while (!isFree(newBomb)) {
    newBomb = getRandomBombCoord();
  }
  return newBomb;
}

void Bomb::setBunchOfBombs() {
  for (unsigned i{0}; i < bombNum; i++) {
    bombsCoord.push_back(setNewBombInFreeCoords());
  }
};

bool Bomb::isFree(BombCoords givenCoord) {
  auto isAlreadyExist = [&givenCoord](BombCoords& bombCoord) {
    return isEqualPairs<BombCoords>(givenCoord, bombCoord);
  };
  auto it = std::find_if(bombsCoord.begin(), bombsCoord.end(), isAlreadyExist);
  bool notOccupied{it == bombsCoord.end()};

  return notOccupied;
}