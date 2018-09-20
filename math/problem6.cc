/**
 * The Modern C++ Challenge, Problem 6
 *
 * Problem description: 
 * ====
 * 6. Abundant numbers
 *
 * Write a program that prints all abundant numbers and their abundance, up to
 * a number entered by the user.
 *
 * Notes:
 * ====
 * This is also a straightforward challenge. There's a slightly more optimized
 * method of getting a number's proper divisors by adding both divisors at
 * once and stopping at sqrt(N) rather than N/2. It doesn't seem to make a
 * huge difference here.
 */

#include <iostream>
#include <stdexcept>
#include <string>

bool isAbundant(const int test, int& abundance);

int main(int argc, char **argv) {
  if (argc != 2) {
    throw std::invalid_argument("must pass 1 argument on command line");
  }

  int limit = std::stoi(argv[1]);
  if (limit < 1) {
    throw std::invalid_argument("argument must be a positive integer");
  }

  for (int i=0; i<=limit; i++) {
    int abundance;
    if (isAbundant(i, abundance)) {
      std::cout << i << " (" << abundance << ")" << std::endl;
    }
  }

  return 0;
}

bool isAbundant(const int test, int& abundance) {
  const int limit = test / 2;
  abundance = 0;
  for (int i=1; i <= limit; i++)
    if (test % i == 0) abundance += i;

  if (abundance > test) {
    return true;
  }

  return false;
}

