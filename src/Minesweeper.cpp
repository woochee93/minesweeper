#include "../include/Minesweeper.hpp"

using namespace utils;

Minesweeper::Minesweeper(const unsigned size)
    : board{std::make_shared<Board>(size)}, bomb{std::make_shared<Bomb>(size)} {};

std::shared_ptr<Bomb> Minesweeper::getBomb() { return bomb; }

std::shared_ptr<Board> Minesweeper::getBoard() { return board; }