#include <stdio.h>

unsigned rightrot(int x, int n);
int pow2(int x, int y);
int numOfBits(int x);

int main() {
  printf("5 (101), 1 => %d (110)\n", rightrot(5, 1));
  printf("58 (111010), 4 => %d (101011)\n", rightrot(58, 4));
  printf("58 (111010), 3 => %d (010111)\n", rightrot(58, 3));
  printf("127, (1111111), 5 => %d (1111111)\n", rightrot(127, 5));
}

unsigned rightrot(int x, int n) {
  int rotateUp = (x & (pow2(2, n) - 1)) << (numOfBits(x) - n);
  int shiftDown = x >> n;
  return rotateUp + shiftDown;
}

int pow2(int x, int y) {
  int n = 1;
  for (; y > 0; --y)
    n = n * x;
  return n;
}

int numOfBits(int x) {
  int i = 0;
  for (; x > 0; ++i)
    x = x >> 1;
  return i;
}
