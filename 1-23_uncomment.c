#include <stdio.h>

void copyText(void);
void deleteSubstring(int start, int end);
int getCommentStart(int cursor);
int getCommentEnd(int cursor);
int isFullLineComment(int cursor);

char text[4096];

int main() {
  copyText();
  printf("%s", text);
  int cursor = 0;

  while (cursor >= 0) {
    int start = getCommentStart(cursor);
    if (start == -1)
      break;

    int end = getCommentEnd(start);
    if (end == -1)
      break;

    if (isFullLineComment(start - 1))
      deleteSubstring(start, end + 1);
    else
      deleteSubstring(start, end);

    cursor = end;
  }
  printf("============================================================\n");
  printf("The output below has been written to file 1-23_output.c\n");
  printf("============================================================\n");
  printf("%s", text);
  FILE *output = fopen("1-23_output.c", "w");
  for (int i = 0; text[i] != 0; ++i) {
    fputc(text[i], output);
  }
  fclose(output);
}

void copyText() {
  char c;
  FILE *f = fopen("comments.c", "r");

  for (int i = 0; (c = fgetc(f)) != EOF; ++i)
    text[i] = c;

  fclose(f);
}

// Use backspace (int 127) to delete unwanted chars from start to end
void deleteSubstring(int start, int end) {
  while (start < end) {
    text[start] = 127;
    ++start;
  }
}

int getCommentStart(int cursor) {
  for (; text[cursor] != 0; ++cursor) {
    if (text[cursor] == '/' && text[cursor - 1] == '/')
      return cursor - 1;
  }
  return -1;
}

int getCommentEnd(int cursor) {
  while (text[cursor] != 0) {
    if (text[cursor] == '\n') {
      return cursor;
    }
    ++cursor;
  }
  return cursor;
}

int isFullLineComment(int cursor) {
  while (cursor > 0) {
    if (text[cursor] == '\n')
      return 1;
    if (text[cursor] != ' ' && text[cursor] != '\t')
      return 0;
    --cursor;
  }
  return 1;
}
