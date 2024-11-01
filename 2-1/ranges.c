#include <limits.h>
#include <math.h>
#include <stdio.h>

int main() {
  int width = 15;
  printf("HEADER DATA\n");

  printf("%2$-*1$s%3$-*1$s%4$-*1$s%5$-*1$s%6$-*1$s%7$-*1$s\n", width, "TYPE",
         "BITS", "BYTES", "MIN", "MAX", "UMAX");

  printf("%2$-*1$s%3$-*1$d%4$-*1$d%5$-*1$d%6$-*1$d%7$-*1$d\n", width, "CHAR",
         (int)log2(UCHAR_MAX + 1), (int)log2(UCHAR_MAX + 1) / 8, CHAR_MIN,
         CHAR_MAX, UCHAR_MAX);

  printf("%2$-*1$s%3$-*1$d%4$-*1$d%5$-*1$d%6$-*1$d%7$-*1$d\n", width, "SHORT",
         (int)log2(USHRT_MAX + 1), (int)log2(USHRT_MAX + 1) / 8, SHRT_MIN,
         SHRT_MAX, USHRT_MAX);

  printf("%2$-*1$s%3$-*1$d%4$-*1$d%5$-*1$.2e%6$-*1$.2e%7$-*1$.2e\n", width,
         "INT", (int)(long)log2((long int)UINT_MAX + 1),
         (int)(long)log2((long int)UINT_MAX + 1) / 8, (double)INT_MIN,
         (double)INT_MAX, (double)UINT_MAX);

  printf("%2$-*1$s%3$-*1$d%4$-*1$d%5$-*1$.2e%6$-*1$.2e%7$-*1$.2e\n", width,
         "LONG", (int)log2f((float)ULONG_MAX + 1),
         (int)log2f((float)ULONG_MAX + 1) / 8, (double)LONG_MIN,
         (double)LONG_MAX, (double)ULONG_MAX);

  printf("====================================================================="
         "==============\n");
  printf("CALCULATED\n");

  unsigned char c = 0;
  printf("CHAR:\t%d\n", --c);

  unsigned short s = 0;
  printf("SHORT:\t%d\n", --s);

  unsigned int n = 0;
  printf("INT:\t%u\n", --n);

  unsigned long l = 0;
  printf("LONG:\t%lu\n", --l);
}
