/**
 * The Modern C++ Challenge, Problem 3
 *
 * Problem description: 
 * ====
 * 3. Least common multiple
 *
 * Write a program that will, given two or more positive integers, calculate
 * and print the least common multiple of them all.
 *
 * Notes:
 * ====
 * I tried to store all the multiples of each number in a vector<int>, then
 * test every multiple of the smallest supplied integer against those. This
 * did not work out. I went with a brute-force approach instead. As it happens,
 * there is a better way to accomplish this using std::accumulate.
 *
 * Preprocessor switches:
 *   -DUSE_CANONICAL: Use (more or less) the solution provided by the book.
 *   -DUSE_OVERWROUGHT: Use my initial overwrought approach
 *                      (not currently working)
 */

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

int main(int argc, char **argv) {
  if (argc < 3) {
    throw std::invalid_argument("Must pass at least 2 integers on command line");
  }

  // capture all arguments into a vector<int>
  std::vector<int> ints;
  for (int i = 1; i < argc; i++) {
    ints.push_back(std::atoi(argv[i]));
  }

#ifdef USE_CANONICAL

  std::cout << std::accumulate(ints.begin(), ints.end(), 1, [](const int a, const int b) -> int {
      int h = std::gcd(a, b);
      return h ? (a * (b / h)) : 0;
      }) << std::endl;

#elif defined USE_OVERWROUGHT

  std::vector<int>::iterator i_least = std::min_element(ints.begin(), ints.end());
  int least = *i_least;
  ints.erase(i_least);

  std::vector<std::vector<int>> multiples;
  for (int i : ints) {
    multiples.push_back({i});
  }

  do {
    bool failed = false;
    int i = multiples.at(0).size();
    std::cout << "size is " << i << std::endl;

    for (std::vector<int>& m : multiples) {
      m.push_back(m[0] * i+1);
      if (std::find(m.begin(), m.end(), least*i) == m.end()) {
        failed = true;
      }
    }

    if (!failed) {
      std::cout << least*i << std::endl;
      break;
    }
  } while(true);

#else

  for (int i=1; ; i++) {
    bool failed = false;
    for (int j : ints)
      if (i % j != 0) 
        failed = true;

    if (!failed) {
      std::cout << i << std::endl;
      break;
    }
  }

#endif

  return 0;
}
    
