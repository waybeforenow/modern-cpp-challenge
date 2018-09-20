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

#ifdef USE_STDLIB

#elif defined USE_DUMMY

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

#elif defined USE_CANONICAL

  std::cout << std::accumulate(ints.begin(), ints.end(), 1, [](const int a, const int b) -> int {
      int h = std::gcd(a, b);
      return h ? (a * (b / h)) : 0;
      }) << std::endl;

#else

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

#endif

  return 0;
}
    
