//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

void printAt(char c, int x, int y) {
  printf("\033[%d;%dH%c", y, x, c);
}

int main() {
  char text[100];
  printf("Enter text to convert to ASCII art:\n");
  fgets(text, 100, stdin);

  int len = strlen(text);
  int rows = 7;
  int cols = len * 6;

  printf("\033[2J"); // clear the console
  printf("\033[H"); // move the cursor to the top-left

  char* asciiArt[] = {
    "     ||      ",
    "     ||      ",
    "    ,||,     ",
    "  ,''''',    ",
    ",,,,,,,,|,_ ",
    "   '*,,,,'   ",
    "     '''     "
  };

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int index = c / 6;
      if (index < len) {
        char ch = text[index];
        int asciiIndex = (int)ch;
        if (asciiIndex < 0 || asciiIndex > 127) {
          asciiIndex = 127; // error character
        }
        int colIndex = (c % 6) + 1;
        if (asciiArt[r][asciiIndex * 8 + colIndex] == ',') {
          printAt('#', c + 1, r + 1);
        } else {
          printAt(' ', c + 1, r + 1);
        }
      } else {
        printAt(' ', c + 1, r + 1);
      }
    }
  }

  printf("\n");
  return 0;
}