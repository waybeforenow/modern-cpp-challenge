/**
 * The Modern C++ Challenge, Problem 12
 *
 * Problem description: 
 * ====
 * 12. Largest Collatz sequence
 *
 * Write a program that determines and prints which number up to 1 million
 * produces the longest Collatz sequence and what its length is.
 *
 * Notes:
 * ====
 * I wrote the function recursively to begin with, anticipating that it would
 * break. It did. I rewrote it non-recursively, and changed the `int` to `long
 * long` so it wouldn't overflow.
 *
 * The book improves on this by clevely caching the length of every input it's
 * processed, to avoid processing the same input twice in the same way. I
 * didn't do that here. I think that I prevented myself from foreseeing this
 * optimization by opting to work backwards from the start. The program runs
 * decently fast without it, anyway.
 */

#include <iostream>
#include <stdexcept>

const int collatzLength(long long term);

int main(int argc, char **argv) {
  int largest_length = 0;
  int largest_first_term;
  for (int i=1000000; i>0; i--) {
    int test = collatzLength(i);
    if (test > largest_length) {
      largest_length = test;
      largest_first_term = i;
    }
  }

  std::cout << largest_first_term << " (" << largest_length << ")"
    << std::endl;

  return 0;
}

const int collatzLength(long long term) {
  int length;
  for (length = 0; term != 1; length++) {
    if (term < 0) {
      throw std::exception();
    }
    if (term % 2 == 0) {
      term /= 2;
    } else {
      term = term * 3 + 1;
    }
  }

  return length;
}

/* Recursive function inlined below, for fun. It overflows the stack.
const int collatzLength(const int& term, const int length) {
  if (term == 1) return length;
  if (term % 2 == 0) {
    return collatzLength(term / 2, length + 1);
  } else {
    return collatzLength(3 * term + 1, length + 1);
  }
}
*/
