#include "../include/Minesweeper.hpp"
#include <gtest/gtest.h>


TEST(bomb, setBunchOfBombs){
   utils::Minesweeper game{};
   game.getBomb()->setAll();
}


TEST(minesweeper, whenBombOnCordReturnFalse) {
  utils::Minesweeper game{};
  utils::BombCoords coords = utils::BombCoords{1,1};
  game.getBomb()->setNewOne(coords);
  EXPECT_TRUE(game.getBomb()->isOccupiedCoord(coords));
}

TEST(minesweeper, generateRandomBombCoordShouldReturnProperRangedPair) {
  unsigned defaultSize = 3;
  utils::Minesweeper game{};
  utils::BombCoords coords = game.getBomb()->getRandomCoord();
  EXPECT_TRUE(coords.first <= (defaultSize - 1));
  EXPECT_TRUE(coords.second <= (defaultSize - 1));
}
