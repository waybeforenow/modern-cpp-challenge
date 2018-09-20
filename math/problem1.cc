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

  for (int i=0; i < limit; i++)
    if (i % 3 == 0 || i % 5 == 0)
      result += i;

  std::cout << result << std::endl;

  return 0;
}
