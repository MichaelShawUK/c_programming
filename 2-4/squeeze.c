#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
  char s1[40] = "hello world";
  char s2[40] = "ol";
  squeeze(s1, s2);
  printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]) {
  for (int i = 0; s1[i] != '\0'; ++i) {
    for (int j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        s1[i] = 127;
        break;
      }
    }
  }
}
