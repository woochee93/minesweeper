#ifndef _GETRNDNUMBER_CPP_
#define _GETRNDNUMBER_CPP_
#include <random>
template <typename NumberType>
NumberType getRndNumber(const NumberType& lowerBand, const NumberType& upperBand) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(lowerBand, upperBand);
return dist6(rng);
};
#endif // _GETRNDNUMBER_CPP_