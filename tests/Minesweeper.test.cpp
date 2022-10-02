#include "../include/Minesweeper.hpp"
#include <gtest/gtest.h>
TEST(board, printBoardSize9) {
   utils::Minesweeper game{9,9};
   game.initGame();
   game.getBoard()->printBoard();
}


TEST(board, printBoardSize3) {
   utils::Minesweeper game{};
   game.initGame();
   game.getBoard()->printBoard();
}


TEST(bomb, setBunchOfBombs){
   utils::Minesweeper game{};
   game.getBomb()->setAll();
}


TEST(minesweeper, whenBombOnCordReturnFalse) {
  utils::Minesweeper game{};
  utils::BoardCoord coords = utils::BoardCoord{1,1};
  game.getBomb()->setOne(coords);
  EXPECT_TRUE(game.getBomb()->isOccupiedCoord(coords));
}

TEST(minesweeper, generateRandomBombCoordShouldReturnProperRangedPair) {
  unsigned defaultSize = 3;
  utils::Minesweeper game{};
  utils::BoardCoord coords = game.getBomb()->getRandomCoord();
  EXPECT_TRUE(coords.first <= (defaultSize - 1));
  EXPECT_TRUE(coords.second <= (defaultSize - 1));
}
