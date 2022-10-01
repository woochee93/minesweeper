#include "../include/Minesweeper.hpp"

using namespace utils;

Minesweeper::Minesweeper(const unsigned size, const unsigned numOfBomb)
    : board{std::make_shared<Board>(size)}, bomb{std::make_shared<Bomb>(size, numOfBomb)} {};

std::shared_ptr<Bomb> Minesweeper::getBomb() { return bomb; }

std::shared_ptr<Board> Minesweeper::getBoard() { return board; }