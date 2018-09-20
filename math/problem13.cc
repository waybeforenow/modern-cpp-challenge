/**
 * The Modern C++ Challenge, Problem 13
 *
 * Problem description: 
 * ====
 * 13. Computing the value of Pi
 *
 * Write a program that computes the value of Pi with a precision of two
 * decimal digits.
 *
 * Notes:
 * ====
 * Many, many ways to skin this cat. I had to choose one of them. I don't
 * think that I chose the right one. The book gives an entirely different
 * algorithm.
 */

#include <iostream>
#include <iomanip>

double makeNilakantha(const int& iters);

int main(int argc, char **argv) {
  const int nilakantha_iters = 100000;

  std::cout << std::setprecision(3) << makeNilakantha(nilakantha_iters)
    << std::endl;

  return 0;
}

double makeNilakantha(const int& iters) {
  double result = 3;
  double denom = 2;

  for (int i=1; i<=iters; i++) {
    if (i % 2 == 0) {
      result -= 4. / (denom * denom+1. * denom+2.);
    } else {
      result += 4. / (denom * denom+1. * denom+2.);
    }

    denom += 2.;
  }

  return result;
}

