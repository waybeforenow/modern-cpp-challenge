#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void makePrimeFactors(const int& test, std::vector<int>* prime_factors);
inline bool isPrime(const int& test);

int main(int argc, char **argv) {
  if (argc != 2) {
    throw std::invalid_argument("must pass 1 argument on command line");
  }

  int input = std::stoi(argv[1]);
  if (input < 1) {
    throw std::invalid_argument("argument must be a positive integer");
  }

  auto prime_factors = new std::vector<int>;
  makePrimeFactors(input, prime_factors);

  for (int& i : *prime_factors) {
    std::cout << i << std::endl;
  }

  return 0;
}

void makePrimeFactors(const int& test, std::vector<int>* prime_factors) {
  const int limit = test / 2;
  for (int i=2; i <= limit; i++) {
    if (test % i == 0 && isPrime(i)) {
      prime_factors->push_back(i);
    }
  }
}

inline bool isPrime(const int& test) {
  if (test == 2) return true;
  if (test % 2 == 0) return false;

  int stop = std::floor(std::sqrt(test));
  for (int i=3; i<=stop; i+=2) {
    if (test % i == 0) return false;
  }

  return true;
}
