#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char input[], char output[]);

char input[] = "Has\t3\tcolumns\nand\t2\trows\n";
char output[256];
char output2[256];

int main() {
  escape(output, input);
  printf("INPUT\n");
  printf("==============================\n");
  printf("%s", input);
  printf("\nESCAPED OUTPUT\n");
  printf("==============================\n");
  printf("%s\n", output);
  unescape(output, output2);
  printf("\nUNESCAPED OUTPUT\n");
  printf("==============================\n");
  printf("%s", output2);
}

void escape(char s[], char t[]) {
  int i, j;
  i = j = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    default:
      s[j++] = t[i];
      break;
    }
    ++i;
  }
  s[j] = '\0';
}

void unescape(char input[], char output[]) {
  int i, j;
  i = j = 0;

  while (input[i] != '\0') {
    switch (input[i]) {
    case '\\':
      if (input[i + 1] == 'n') {
        output[j++] = '\n';
        i = i + 2;
        break;
      }
      if (input[i + 1] == 't') {
        output[j++] = '\t';
        i = i + 2;
        break;
      }
      output[j++] = '\\';
      ++i;
      break;
    default:
      output[j++] = input[i++];
      break;
    }
  }
  output[j] = '\0';
}
