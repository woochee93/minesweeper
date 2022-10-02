#include "../include/BoardCoord.hpp"

using namespace utils;

bool BoardCoord::operator==(const BoardCoord& other) const {
  return first == other.first && second == other.second;
};