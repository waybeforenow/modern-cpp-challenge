/**
 * The Modern C++ Challenge, Problem 4
 *
 * Problem description: 
 * ====
 * 4. Largest prime smaller than given number
 *
 * Write a program that computes and prints the largest prime number that is
 * smaller than a number provided by the user, which must be a positive
 * integer.
 *
 * Notes:
 * ====
 * Brute force method again; I considered implementing a 2-strong pseudoprime
 * test instead, but it's a bit complicated.
 *
 * Not entirely brute force since we're testing against mod 2, mod 3, mod 5,
 * mod 7, mod 9, etc... but it's fairly inefficient.
 */

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

