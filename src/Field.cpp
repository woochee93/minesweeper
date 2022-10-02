#include "../include/Field.hpp"

using namespace utils;

bool Field::operator==(const Field& other) const {
  return first == other.first && second == other.second;
};