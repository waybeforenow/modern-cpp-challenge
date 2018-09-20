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

