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
      std::cout << "Uh oh. We ended up with a negative term." << std::endl;
      std::cout << " Term: " << term << std::endl;
      std::cout << " Length: " << length << std::endl;
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
