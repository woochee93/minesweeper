#ifndef _BOARDCOORD_HPP_
#define _BOARDCOORD_HPP_
namespace utils {
struct BoardCoord {
  unsigned first;
  unsigned second;
  char value{'0'};
  bool operator==(const BoardCoord& other) const;
};
} // namespace utils
#endif // _BOARDCOORD_HPP_
