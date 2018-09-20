/**
 * The Modern C++ Challenge, Problem 1
 *
 * Problem description: 
 * ====
 * 1. Sum of naturals divisible by 3 and 5
 * Write a program that calculates and prints the sum of all the natural
 * numbers divisible by either 3 or 5, up to a given limit entered by the user.
 *
 * Notes:
 * ====
 * This challenge was simple and straightforward. First we convert the
 * argument from string -> int, then iterate upward from 0. The for-loop
 * starts at 3 as a small optimization.
 */

#include <iostream>
#include <string>
#include <stdexcept>

int main(int argc, char **argv) {
  // check for correct # of arguments
  if (argc != 2) {
    throw std::invalid_argument("Must provide 1 numerical argument on command line");
  }
  
  int limit = std::stoi(argv[1]);

  int result = 0;

  for (int i=3; i < limit; i++)
    if (i % 3 == 0 || i % 5 == 0)
      result += i;

  std::cout << result << std::endl;

  return 0;
}
