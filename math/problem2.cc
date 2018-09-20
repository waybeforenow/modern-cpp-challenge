#include <iostream>
#include <stdexcept>
#include <string>

#ifdef USE_STDLIB
#include <numeric>
#endif

int main(int argc, char **argv) {
  // check for # of arguments
  if (argc != 3) {
    throw std::invalid_argument("must pass 2 numbers on command line");
  }

  int a = std::stoi(argv[1]);
  int b = std::stoi(argv[2]);

#ifdef USE_STDLIB
  std::cout << std::gcd(a, b);
  return 0;
#else
  int *low = (a < b) ? &a : &b;
  int *high = (low == &b) ? &a : &b;

  for (int i = *low; i != 0; i--) {
    if (*low % i == 0 && *high % i == 0) {
      std::cout << i;
      return 0;
    }
  }

  return 2; // no common denominator found
#endif
}
