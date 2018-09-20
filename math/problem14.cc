/**
 * The Modern C++ Challenge, Problem 14
 *
 * Problem description: 
 * ====
 * 14. Validating ISBNs
 *
 * Write a program that validates that 10-digit values entered by the user,
 * as a string, represent valid ISBN-10 numbers.
 *
 * Notes:
 * ====
 * Wikipedia says[1] that ISBNs have to pass the weighted-sum algorithm
 * forwards and backwards. The solution in the book only does it backwards.
 * Also it uses `std::string_view` instead of `const char*`, and folds a
 * lambda function into `std::accumulate` instead of what I'm doing here with
 * the for loop.
 *
 * [1] https://en.wikipedia.org/wiki/International_Standard_Book_Number
 */

#include <iostream>
#include <stdexcept>
#include <cstring>

bool isValidIsbn10(const char *isbn);

int main(int argc, char **argv) {
  if (argc < 2) {
    throw std::invalid_argument("must pass at least 1 ISBN as argument");
  }

  for (int i=1; i<argc; i++) {
    if (isValidIsbn10(argv[i])) {
      std::cout << "SUCCESS: " << argv[i] << " is valid ISBN." << std::endl;
    } else {
      std::cout << "ERROR:   " << argv[i] << " is invalid ISBN." << std::endl;
      return 2;
    }
  }

  return 0;
}

bool isValidIsbn10(const char *isbn) {
  if (strlen(isbn) != 10) return false;
  int check_desc = 0;
  int check_asc = 0;
  
  for (int i=0; i<10; i++) {
    if (isbn[i] < '0' || isbn[i] > '9') return false;
    char test = isbn[i] - '0';
    check_desc += test * (10 - i);
    check_asc += test * (i + 1);
  }

  return (
      check_desc % 11 == 0 && 
      check_asc  % 11 == 0
  );
}

