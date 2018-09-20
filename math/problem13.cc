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

