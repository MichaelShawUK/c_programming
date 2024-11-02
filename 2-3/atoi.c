#include <stdio.h>

int atoi(char s[]);

int main() {
  char number[2] = "12";
  printf("Converting the string \"%s\" to an int\n", number);
  printf("%d\n", atoi(number));
}

int atoi(char s[]) {
  int i, n;

  n = 0;
  for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}
