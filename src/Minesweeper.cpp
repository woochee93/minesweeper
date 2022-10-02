#include "../include/Minesweeper.hpp"

using namespace utils;

Minesweeper::Minesweeper(const unsigned size, const unsigned numOfBomb)
    : bomb{std::make_shared<Bomb>(size, numOfBomb)},
      board{std::make_shared<Board>(size)} {};

void Minesweeper::init() {
  getBomb()->setAll();
  auto coordOfAllBombs = bomb->getBombFields();
  board->init(coordOfAllBombs);
}

std::shared_ptr<Bomb> Minesweeper::getBomb() { return bomb; }

std::shared_ptr<Board> Minesweeper::getBoard() { return board; }