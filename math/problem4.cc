#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

inline bool isPrime(const int test);
inline int findLargestPrime(int smaller_than);

int main(int argc, char **argv) {
  if (argc != 2) {
    throw std::invalid_argument("Must pass 1 numerical argument");
  }

  int largest = std::stoi(argv[1]);
  if (largest < 1) {
    throw std::invalid_argument("Argument must be a positive integer");
  }

  std::cout << findLargestPrime(largest) << std::endl;
  
  return 0;
}

inline bool isPrime(const int test) {
  if (test == 2) return true;
  if (test % 2 == 0) return false;

  double stop = std::sqrt(test);
  for (int i=3; i<stop; i+=2) {
    if (test % i == 0) return false;
  }

  return true;
}

inline int findLargestPrime(int smaller_than) {
  for (; smaller_than > 1; smaller_than--) {
    if (isPrime(smaller_than)) return smaller_than;
  }

  return 1;
}

