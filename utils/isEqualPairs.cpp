#ifndef _ISEQUALPAIRS_CPP_
#define _ISEQUALPAIRS_CPP_
#include <utility>
template <class PairType>
bool isEqualPairs(PairType firstPair, PairType secondPair) {
  bool sameFirstElement{firstPair.first == secondPair.first};
  bool sameSecondElement{firstPair.second == secondPair.second};
  return sameFirstElement && sameSecondElement;
};
#endif // _ISEQUALPAIRS_CPP_