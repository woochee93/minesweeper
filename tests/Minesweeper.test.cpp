#include "../include/Minesweeper.hpp"
#include <gtest/gtest.h>


TEST(bomb, setBunchOfBombs){
   utils::Minesweeper game{};
   game.getBomb()->setAll();
}


TEST(minesweeper, whenBombOnCordReturnFalse) {
  utils::Minesweeper game{};
  utils::BombCoord coords = utils::BombCoord{1,1};
  game.getBomb()->setOne(coords);
  EXPECT_TRUE(game.getBomb()->isOccupiedCoord(coords));
}

TEST(minesweeper, generateRandomBombCoordShouldReturnProperRangedPair) {
  unsigned defaultSize = 3;
  utils::Minesweeper game{};
  utils::BombCoord coords = game.getBomb()->getRandomCoord();
  EXPECT_TRUE(coords.first <= (defaultSize - 1));
  EXPECT_TRUE(coords.second <= (defaultSize - 1));
}
