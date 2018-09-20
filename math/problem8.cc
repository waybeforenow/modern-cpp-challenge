/**
 * The Modern C++ Challenge, Problem 8
 *
 * Problem description: 
 * ====
 * 8. Armstrong numbers
 *
 * Write a program that prints all Armstrong numbers with three digits.
 *
 * Notes:
 * ====
 * Though the book gives an algorithm that assumes the number of digits will
 * always be 3, I wanted to work this out so we could use the same algorithm
 * for other ranges. I ended up working it out by hand, so I'm not sure how
 * optimized it really is.
 *
 * Relies on <cmath> to do the heavy lifting with digit-counting, isolating
 * individual digits, and performing arbitrary exponentation.
 */

#include <cmath>
#include <iostream>
#include <vector>

bool isArmstrongNumber(const int& test);

int main(int argc, char **argv) {
  for (int i=100; i<1000; i++) {
    if (isArmstrongNumber(i)) {
      std::cout << i << std::endl;
    }
  }

  return 0;
}

bool isArmstrongNumber(const int& test) {
  const int num_digits = std::floor(std::log10(test)) + 1;
  std::vector<char> digits;
  digits.reserve(num_digits);

  for (int i=0; i<num_digits; i++) {
    digits.push_back(
        std::floor(test / std::pow(10, i)) -
        std::floor(test / std::pow(10, i+1)) * 10
    );
  }

  int acc = 0;
  for (char& i : digits)
    acc += std::pow(i, num_digits);

  return (acc == test);
}

