#include "../include/Bomb.hpp"
#include <iostream>

using namespace utils;

Bomb::Bomb(const unsigned boardSize, const unsigned numOfBomb)
    : size{boardSize}, bombNum{numOfBomb} {};

void utils::Bomb::setBomb(unsigned x, unsigned y) {
  bombsCoord.push_back(utils::BombCoords(x, y));
}

BombCoords Bomb::generateRandomBombCoord() {
  std::random_device dev;
  std::mt19937 rng(dev());
  unsigned upperBand = size - 1;
  unsigned lowerBand = 0;
  std::uniform_int_distribution<std::mt19937::result_type> dist6(lowerBand,
                                                                 upperBand);

  return BombCoords{dist6(rng), dist6(rng)};
};

BombCoords Bomb::setNewBombInFreeCoords (){
   BombCoords newBomb = generateRandomBombCoord();
  while (!isFree(newBomb)) {
      newBomb = generateRandomBombCoord();
    }
    std::cout<<"New bomb first: "<<newBomb.first<<" second: "<<newBomb.second<<std::endl;
    return newBomb;
}


void Bomb::setBunchOfBombs() {
  for (unsigned i{0}; i < bombNum; i++) {
    bombsCoord.push_back(setNewBombInFreeCoords());
  }
};



bool Bomb::isFree(BombCoords givenCord) {

  std::function<bool(BombCoords)> isAlreadyExist{[&givenCord](BombCoords cords) {
    bool sameFirstElement{givenCord.first == cords.first};
    bool sameSecondElement{givenCord.second == cords.second};
    return sameFirstElement && sameSecondElement;
  }};

  auto it = std::find_if(bombsCoord.begin(), bombsCoord.end(), isAlreadyExist);
  bool notOccupied{it == bombsCoord.end()};
  return notOccupied;
}