#include <stdio.h>

void getInput(void);
void match(void);

char text[1024];

int main() {
  getInput();
  printf("%s", text);
  match();
}

void match() {
  int parentheses = 0;
  int curly = 0;
  int square = 0;
  for (int i = 0; text[i] != 0; ++i) {
    if (text[i] == '(')
      --parentheses;
    if (text[i] == '{')
      --curly;
    if (text[i] == '[')
      --square;
    if (text[i] == ')')
      ++parentheses;
    if (text[i] == '}')
      ++curly;
    if (text[i] == ']')
      ++square;
  }
  if (parentheses == 0 && curly == 0 && square == 0)
    printf("All brackets match\n");

  if (parentheses > 0)
    printf("Missing opening parentheses: (\n");
  if (parentheses < 0)
    printf("Missing closing parentheses: )\n");
  if (curly > 0)
    printf("Missing opening curly bracket: {\n");
  if (curly < 0)
    printf("Missing closing curly bracket: }\n");
  if (square > 0)
    printf("Missing opening square bracket: [\n");
  if (square < 0)
    printf("Missing closing square bracket: ]\n");
}

void getInput() {
  FILE *f = fopen("input.txt", "r");
  char c;

  for (int i = 0; (c = fgetc(f)) != EOF; ++i)
    text[i] = c;
}
