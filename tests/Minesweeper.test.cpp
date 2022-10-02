#include "../include/Minesweeper.hpp"
#include <gtest/gtest.h>
int countCharRepetitionsInStr(std::string str, char character) {
  int count{};
  for (auto c : str) {
    if (c == character) {
      count++;
    }
  }
  return count;
}

TEST(board, print9Rows) {
  utils::Minesweeper game{9, 9};
  game.init();
  testing::internal::CaptureStdout();
  game.getBoard()->print();
  std::string output = testing::internal::GetCapturedStdout();
  int numOfPrintedBombs = countCharRepetitionsInStr(output, '\n');
  EXPECT_EQ(numOfPrintedBombs, 9);
}

TEST(board, printWith9BombsPrint9Bombs) {
  utils::Minesweeper game{9, 9};
  game.init();
  testing::internal::CaptureStdout();
  game.getBoard()->print();
  std::string output = testing::internal::GetCapturedStdout();
  int numOfPrintedBombs = countCharRepetitionsInStr(output, 'B');
  EXPECT_EQ(numOfPrintedBombs, 9);
}

TEST(board, printWithDefaultNumOfBombsPrintThreeBombs) {
  utils::Minesweeper game{};
  game.init();
  testing::internal::CaptureStdout();
  game.getBoard()->print();
  std::string output = testing::internal::GetCapturedStdout();
  int numOfPrintedBombs = countCharRepetitionsInStr(output, 'B');
  EXPECT_EQ(numOfPrintedBombs, 3);
}

TEST(bomb, setBunchOfBombs) {
  utils::Minesweeper game{};
  game.getBomb()->setAll();
}

TEST(minesweeper, whenBombOnCordReturnFalse) {
  utils::Minesweeper game{};
  utils::Field coords = utils::Field{1, 1};
  game.getBomb()->setOne(coords);
  EXPECT_TRUE(game.getBomb()->isOccupiedField(coords));
}

TEST(minesweeper, generateRandomBombCoordShouldReturnProperRangedPair) {
  unsigned defaultSize = 3;
  utils::Minesweeper game{};
  utils::Field coords = game.getBomb()->getRandomField();
  EXPECT_TRUE(coords.first <= (defaultSize - 1));
  EXPECT_TRUE(coords.second <= (defaultSize - 1));
}
