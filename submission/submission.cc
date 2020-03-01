#include "submission.h"

#include <string>

bool prime(int x) {
  for (int i = 2; i < x / 2; ++i) {
    if (x % i != 0) {
      return false;
    }
  }
  return true;
}

std::string reverse(const std::string &x) {
  return std::string(x.rend(), x.rbegin());
}
