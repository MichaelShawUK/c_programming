#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);
unsigned getRemainder(unsigned x, int p, int n);

int main() {
  // (173, 5, 4)
  // 10101101 173
  //   ^^^^   invert
  // Result
  // 10010001 145
  printf("%d\n", invert(173, 5, 4));
}

unsigned invert(unsigned x, int p, int n) {
  // 1. Save right most bits after inversion selection
  //    01
  unsigned remainder = getRemainder(x, p, n);

  // 2. Right shift number to get end of inversion selection at position 0
  //    (p + 1 - n)
  //    10101101 >> 2 = 00101011
  //      ^^^^              ^^^^
  x = x >> (p + 1 - n);

  // 3. Save inversion selection bitfield
  //    1011
  unsigned bitfield = getbits(x, n - 1, n);

  // 4. Right shift again to get start of inversion selection at position 0
  //    n
  //    00101011 >> 4 = 00000010
  //        ^^^^
  x = x >> n;

  // 5. Left shift the size of inversion selection
  //    n
  //    00000010 << 4 = 00100000
  x = x << n;

  // 6. Add the inverted inversion selection bitfield
  //    00100000 + ~1011
  //    00100000 + 0100 = 00100100 (32 + 4 = 36)
  x = x + getbits(~bitfield, n - 1, n);

  // 7. Left shift the size of remainder
  //    (p + 1 - n)
  //    00100100 << 2 = 10010000
  x = x << (p + 1 - n);

  // 8. Add remainder
  //    10010000 + 01 = 10010001 (144 + 1 = 145)
  x = x + remainder;

  return x;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned getRemainder(unsigned x, int p, int n) {
  unsigned initial = x;
  x = x >> (p + 1 - n);
  x = x << (p + 1 - n);
  return initial - x;
}
