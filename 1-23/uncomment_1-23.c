#include <stdio.h>
// TODO:  Identify index for start of comment
//        Search forwards from index for '\n' || '\0', EOF
//        Search backwards from index for '\n' or index 0 if full line comment
//          - or search backwards for a non-whitespace char for trailing comment
//          - decrement index if ' ' || '\t'
//        Delete substring for beginning and end index

void copyText(void);
void deleteSubstring(int start, int end);
int getCommentStart(int cursor);
int getCommentEnd(int cursor);
int trackBack(int cursor);
void writeToFile(void);

char text[4096];
char output[4096];

int main() {
  copyText();
  int cursor = 0;

  while (1) {
    int start = getCommentStart(cursor);
    if (start == -1)
      break;

    int origin = trackBack(start - 1);
    int end = getCommentEnd(start);
    if (origin < 0) {
      deleteSubstring((origin * -1), end);
    } else {
      deleteSubstring(origin, end + 1);
    }

    cursor = start + 2;
  }

  printf("%s", text);
  printf("========================================\n");
  printf("%s", output);
  writeToFile();
}

void copyText() {
  char c;
  FILE *f = fopen("comments_1-23.c", "r");

  for (int i = 0; (c = fgetc(f)) != EOF; ++i) {
    text[i] = c;
    output[i] = c;
  }

  fclose(f);
}

// Use backspace (int 127) to delete unwanted chars from start to end
void deleteSubstring(int start, int end) {
  while (start < end) {
    output[start] = 127;
    ++start;
  }
}

// Returns index of where to delete from (negative if its a trailing comment)
int trackBack(int cursor) {
  while (1) {
    if (cursor <= 0)
      return 0;
    if (text[cursor] == ' ') {
      --cursor;
      continue;
    }
    if (text[cursor] == '\n') {
      return cursor + 1;
    }
    if (text[cursor] != '\n') {
      return (cursor + 1) * -1;
    }
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

void writeToFile() {
  FILE *f = fopen("output_1-23.c", "w");
  for (int i = 0; output[i] != 0; ++i) {
    if (output[i] != 127) {
      fputc(output[i], f);
    }
  }
  fclose(f);
}
