#include "../include/Minesweeper.hpp"
#include <gtest/gtest.h>


TEST(bomb, setBunchOfBombs){
   utils::Minesweeper game{};
   game.getBomb()->setBunchOfBombs();
}


TEST(minesweeper, whenBombOnCordReturnFalse) {
  utils::Minesweeper game{};
  utils::BombCoords coords = utils::BombCoords{1,1};
  game.getBomb()->setBomb(coords.first,coords.second);
  EXPECT_FALSE(game.getBomb()->isFree(coords));
}

TEST(minesweeper, generateRandomBombCoordShouldReturnProperRangedPair) {
  unsigned defaultSize = 3;
  utils::Minesweeper game{};
  utils::BombCoords coords = game.getBomb()->generateRandomBombCoord();
  EXPECT_TRUE(coords.first <= (defaultSize - 1));
  EXPECT_TRUE(coords.second <= (defaultSize - 1));
}
