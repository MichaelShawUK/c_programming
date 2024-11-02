#include <ctype.h>
#include <stdio.h>
#include <string.h>

int htoi(char s[]);

int main() {
  char *hexa = "0Xffeeff";
  int length = strlen(hexa);
  printf("%-*s%s\n", length + 5, "HEX", "DEC");
  printf("%-*s%d\n", length + 5, hexa, htoi(hexa));
}

int htoi(char s[]) {
  int i = 0;
  int n = 0;

  if (s[1] == 'x' || s[1] == 'X')
    i = 2;

  while (s[i] != '\0') {
    char c = s[i];

    if (isdigit(c))
      n = n * 16 + (c - '0');

    if (isalpha(c)) {
      c = tolower(c);
      n = n * 16 + (c - 87);
    }

    ++i;
  }

  return n;
}
