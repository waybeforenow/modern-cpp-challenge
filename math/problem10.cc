#include <bitset>
#include <iostream>

const int grayEncode(const unsigned int &to_encode);
const int grayDecode(unsigned int to_decode);

int main(int argc, char **argv) {
  // 0x20 = b00100000
  for (unsigned int i=0; i<0x20; i++) {
    const unsigned int encoded = grayEncode(i);

    std::cout << "Binary representation:    " << std::bitset<5>(i) << std::endl;
    std::cout << "Gray code representation: " << std::bitset<5>(encoded)
      << std::endl;
    std::cout << "Decoded Gray code value:  "
      << std::bitset<5>(grayDecode(encoded)) << std::endl;

    std::cout << std::endl;
  }

  return 0;
}

const int grayEncode(const unsigned int &to_encode) {
  return to_encode ^ (to_encode >> 1);
}

const int grayDecode(unsigned int to_decode) {
   for (unsigned int bit = 1U << 31; bit > 1; bit >>= 1) {
      if (to_decode & bit) to_decode ^= bit >> 1;
   }
   return to_decode;
}

