#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

inline bool isPrime(const int test);

int main(int argc, char **argv) {
  if (argc != 2) {
    throw std::invalid_argument("must pass 1 numerical argument");
  }

  int limit = std::stoi(argv[1]);
  if (limit < 1) {
    throw std::invalid_argument("argument must be a positive integer");
  }

  // first sexy prime pair terminates at 11, so make that our lower bound
  for (int i=11; i <= limit; i++) {
    if (isPrime(i) && isPrime(i-6)) {
      std::cout << "(" << i-6 << ", " << i << ")" << std::endl;
    }
  }

  return 0;
}

inline bool isPrime(const int test) {
  if (test % 2 == 0) return false;

  double stop = std::sqrt(test);
  for (int i=3; i<stop; i+=2) {
    if (test % i == 0) return false;
  }

  return true;
}
