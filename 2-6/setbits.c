#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);

int main() {
  unsigned res = setbits(1, 3, 2, 3);
  printf("%d\n", res);
}

unsigned setbits(unsigned x, int p, int n, int y) {
  if (n <= 0)
    return x;

  return x | (getbits(y, n - 1, n) << (p + 1 - n));
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}
