#include "../include/Bomb.hpp"

void utils::Bomb::setBomb(unsigned x, unsigned y) {
  bombsCoord.push_back(utils::BombCoords(x, y));
}

utils::BombCoords utils::Bomb::generateRandomBombCoord() {
  std::random_device dev;
  std::mt19937 rng(dev());
  unsigned upperBand = size - 1;
  unsigned lowerBand = 0;
  std::uniform_int_distribution<std::mt19937::result_type> dist6(lowerBand,
                                                                 upperBand);

  return BombCoords{dist6(rng), dist6(rng)};
};

void utils::Bomb::setBunchOfBombs() {
  bombsCoord.push_back(generateRandomBombCoord());
};

bool utils::Bomb::isFree(BombCoords cord) {

  std::function<bool(BombCoords)> isAlreadyExist{[&cord](BombCoords cords) {
    bool sameFirstElement{cord.first == cords.first};
    bool sameSecondElement{cord.second == cords.first};
    return sameFirstElement && sameSecondElement;
  }};
  auto it = std::find_if(bombsCoord.begin(), bombsCoord.end(), isAlreadyExist);
  bool notOccupied{it == bombsCoord.end()};
  return notOccupied;
}