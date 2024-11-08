#include <ctype.h>
#include <stdio.h>

int main() {
  char str[128] = "Hello World!";

  for (int i = 0; str[i] != '\0'; ++i) {
    printf("%c", (isupper(str[i]) ? str[i] + 32 : str[i]));
  }
}
