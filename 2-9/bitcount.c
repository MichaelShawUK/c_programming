#include <stdio.h>

int bitcount(unsigned x);

int main() {
  // bitcount returns the number of bits for given integer
  printf("%d\n", bitcount(129));
}

int bitcount(unsigned x) {
  int i;
  for (i = 0; x > 0; x &= x - 1) {
    ++i;
  }
  return i;
}
