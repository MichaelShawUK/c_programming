#include <stdio.h>
#define WIDTH 50

int getLastSpace(void);
void printSlice(int endIndex);
int dropToNewLine(int index);

char line[WIDTH + 1];

int main() {
  FILE *lorem = fopen("lorem.txt", "r");
  char c;
  int i;

  for (i = 0; (c = fgetc(lorem)) != EOF; ++i) {
    /* putchar(c); */
    line[i] = c;
    if (i >= WIDTH) {
      /* printf("%s\n", line); */
      int index = getLastSpace();
      /* printf("Last space at position: %d\n", getLastSpace()); */
      printSlice(index);
      /* putchar('\n'); */
      i = dropToNewLine(index) - 1;
    }
  }
  line[i] = '\0';
  printf("%s", line);

  fclose(lorem);
}

int getLastSpace() {
  int lastSpace = -1;

  for (int i = 0; i <= WIDTH; ++i) {
    if (line[i] == ' ')
      lastSpace = i;
  }
  return lastSpace;
}

void printSlice(int endIndex) {
  for (int i = 0; i < endIndex; ++i) {
    putchar(line[i]);
  }
  putchar('\n');
}

int dropToNewLine(int index) {
  int diff = WIDTH - index;

  for (int i = 0; index <= WIDTH; ++i) {
    line[i] = line[index + 1];
    ++index;
  }

  return diff;
}
