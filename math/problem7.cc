/**
 * The Modern C++ Challenge, Problem 7
 *
 * Problem description: 
 * ====
 * 7. Amicable numbers
 *
 * Write a program that prints the list of all pairs of amicable numbers
 * smaller than 1,000,000. 
 *
 * Notes:
 * ====
 * Right on, this more-or-less reuses the abundance test function from the
 * previous challenge. This time we don't care if a number is abundant per se,
 * we only want to test if its abundance is commutative.
 *
 * We keep around a std::set this time to avoid checking any number twice.
 * This doesn't seem to add a measurable performance hit.
 */

#include <iostream>
#include <set>

bool hasAmicablePair(const int& test, int& other_half);
const int abundance(const int& test);

int main(int argc, char **argv) {
  const int limit = 200000;

  std::set<int> already_seen;
  for (int i=220; i<=limit; i++) {
    if (already_seen.count(i) == 0) {
      int other_half;
      if (hasAmicablePair(i, other_half)) {
        already_seen.insert(other_half);
        std::cout << "(" << i << ", " << other_half << ")" << std::endl;
      }
    }
  }

  return 0;
}

bool hasAmicablePair(const int& test, int& other_half) {
  other_half = abundance(test);
  return (other_half != test && abundance(other_half) == test);
}

const int abundance(const int& test) {
  const int limit = test / 2;
  int abundance = 0;
  for (int i=1; i <= limit; i++)
    if (test % i == 0) abundance += i;

  return abundance;
}

