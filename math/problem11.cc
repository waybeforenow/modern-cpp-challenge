/**
 * The Modern C++ Challenge, Problem 11
 *
 * Problem description: 
 * ====
 * 11. Converting numerical values to Roman
 *
 * Write a program that, given a number entered by the user, prints its Roman
 * numeral equivalent. 
 *
 * Notes:
 * ====
 * The vector<pair> at the beginning used to be a map<int, string> until I
 * read the solution given by the book. That's a reminder for me not to reach
 * for more complicated abstractions just because the data structure got a
 * little more complex.
 *
 * Other than that, the solution I came up with was substantially similar to
 * the book solution. I got tripped up on IV, IX, XL, etc. of course. However,
 * it was a small hurdle.
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

const std::vector<std::pair<int, std::string>> numerals =
  { {1,    "I" }
  , {4,    "IV"}
  , {5,    "V" }
  , {9,    "IX"}
  , {10,   "X" }
  , {40,   "XL"}
  , {50,   "L" }
  , {90,   "XC"}
  , {100,  "C" }
  , {400,  "CD"}
  , {500,  "D" }
  , {900,  "CM"}
  , {1000, "M" }
  };

int main(int argc, char **argv) {
  if (argc != 2) {
    throw std::invalid_argument("Must pass 1 numerical argument");
  }

  int input = std::stoi(argv[1]);
  if (input < 1) {
    throw std::invalid_argument("Argument must be a positive integer");
  }

  std::string result;
  for (auto it = numerals.rbegin(); it != numerals.rend(); it++) {
    while (input >= it->first) {
      input -= it->first;
      result.append(it->second);
    }

    if (input == 0) break;
  }

  std::cout << result << std::endl;

  return 0;
}

