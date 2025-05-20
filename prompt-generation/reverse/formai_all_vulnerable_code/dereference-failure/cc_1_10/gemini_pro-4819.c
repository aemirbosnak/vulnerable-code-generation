//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define RESET   "\x1b[0m"

int main() {
  // Parse input
  char *input = NULL;
  size_t len = 0;
  getline(&input, &len, stdin);

  // Convert input to uppercase
  for (char *c = input; *c != '\0'; c++) {
    *c = toupper(*c);
  }

  // Convert input to color code
  char *color = NULL;
  switch (input[0]) {
    case 'R':
      color = RED;
      break;
    case 'G':
      color = GREEN;
      break;
    case 'Y':
      color = YELLOW;
      break;
    case 'B':
      color = BLUE;
      break;
    case 'M':
      color = MAGENTA;
      break;
    case 'C':
      color = CYAN;
      break;
    case 'W':
      color = WHITE;
      break;
    default:
      color = RESET;
      break;
  }

  // Print color code
  printf("%s%s%s", color, input + 1, RESET);

  return 0;
}