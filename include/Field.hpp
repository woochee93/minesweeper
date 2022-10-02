#ifndef _FIELD_HPP_
#define _FIELD_HPP_
namespace utils {
struct Field {
  unsigned first;
  unsigned second;
  char value{'0'};
  bool reveal{false};
  bool operator==(const Field& other) const;
};
} // namespace utils
#define _FIELD_HPP_
#endif // 
