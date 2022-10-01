#include "../include/Minesweeper.hpp"

using namespace utils;

Minesweeper::Minesweeper(const unsigned size): boardSize{size},bomb{std::make_shared<Bomb>(size)}{};

std::shared_ptr<Bomb> Minesweeper::getBomb(){
    return bomb;
   }