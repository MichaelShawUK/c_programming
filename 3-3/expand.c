#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
  char expansion[256];
  expand("c-x", expansion);
  printf("%s\n", expansion);
}

void expand(char s1[], char s2[]) {
  int start = s1[0];
  int end = s1[2];

  for (int i = start, j = 0; i <= end; ++i, ++j) {
    s2[j] = i;
  }
}
