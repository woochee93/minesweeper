#include "../include/Minesweeper.hpp"
#include <gtest/gtest.h>



TEST(minesweeper, whenBombOnCordReturnFalse) {
 // unsigned defaultSize = 3;
  utils::Minesweeper game{};
  utils::BombCoords coords = utils::BombCoords{1,1};
  game.getBomb()->setBomb(coords.first,coords.second);
  std::cout << coords.first<< " " << coords.second;
  EXPECT_FALSE(game.getBomb()->isFree(coords));
}

TEST(minesweeper, generateRandomBombCoordShouldReturnProperRangedPair) {
  unsigned defaultSize = 3;
  utils::Minesweeper game{};
  utils::BombCoords coords = game.getBomb()->generateRandomBombCoord();
  EXPECT_TRUE(coords.first <= (defaultSize - 1));
  EXPECT_TRUE(coords.second <= (defaultSize - 1));
}
