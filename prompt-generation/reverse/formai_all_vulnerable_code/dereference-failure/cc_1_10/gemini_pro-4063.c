//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// Function to convert a character to an ASCII art representation
char* char_to_art(char c) {
  switch (c) {
    case 'A': return "  __  \n |  | \n |  | \n |  | \n |  | \n |__| ";
    case 'B': return "  __  \n |  | \n |__| \n |  | \n |__| \n  __| ";
    case 'C': return "   __  \n  /  | \n |    \n |    \n |    \n  \__  ";
    case 'D': return "  __  \n |  | \n |  | \n |  | \n |  | \n  __| ";
    case 'E': return "  __  \n |  | \n |__| \n |    \n |__| \n  __| ";
    case 'F': return "  __  \n |  | \n |__| \n |    \n |    \n |    ";
    case 'G': return "   __  \n  /  | \n |    \n |  __\n |__| \n  __| ";
    case 'H': return " |    \n |__  \n |__| \n |__  \n |    \n |    ";
    case 'I': return "  __  \n |  | \n |  | \n |  | \n |  | \n  __| ";
    case 'J': return "    __\n     | \n     | \n     | \n  __| \n |__  ";
    case 'K': return " |    \n |   \n |__  \n |   \n |    \n |    ";
    case 'L': return " |    \n |    \n |    \n |    \n |__| \n  __| ";
    case 'M': return "|     |\n|__ __|\n|  |  |\n|__|__|\n|    |\n|    |";
    case 'N': return "|  __ |\n| |__| |\n|  __| |\n| |__| |\n|    | |\n|    | |";
    case 'O': return "  __  \n |  | \n |  | \n |  | \n |  | \n  __| ";
    case 'P': return "  __  \n |  | \n |__| \n |    \n |    \n  __| ";
    case 'Q': return "  __  \n |  | \n |  | \n |  | \n |__| \n  __| ";
    case 'R': return "  __  \n |  | \n |__| \n |   \n |   \n  __| ";
    case 'S': return "   __  \n  /  | \n |    \n  \__  \n ____| \n|    |";
    case 'T': return "  __  \n |  | \n |  | \n |__| \n |   \n |   ";
    case 'U': return " |    \n |    \n |    \n |    \n |    \n  __| ";
    case 'V': return " |    \n |    \n |    \n |    \n  \__  \n   __|";
    case 'W': return "|     |\n|__ __|\n|  |  |\n|  |  |\n|  |  |\n |__| |";
    case 'X': return " |    \n |    \n  \__  \n    |  \n    |  \n    |  ";
    case 'Y': return "|     |\n|     |\n |  | |\n  \__  \n    |  \n    |  ";
    case 'Z': return "  __  \n |  | \n |  | \n |  | \n |  | \n  __| ";
    default: return " ";
  }
}

// Function to convert a string to an ASCII art representation
char* string_to_art(char* str) {
  int len = strlen(str);
  int width = len * 6;
  int height = 6;
  char* art = malloc(width * height * sizeof(char));

  for (int i = 0; i < len; i++) {
    char* char_art = char_to_art(str[i]);
    for (int j = 0; j < height; j++) {
      for (int k = 0; k < 6; k++) {
        art[i * 6 * height + j * width + k] = char_art[j * 6 + k];
      }
    }
  }

  return art;
}

// Function to print an ASCII art representation of a string
void print_art(char* art, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", art[i * width + j]);
    }
    printf("\n");
  }
}

int main() {
  char* str = "Hello, ASCII art!";
  char* art = string_to_art(str);

  int width = strlen(str) * 6;
  int height = 6;

  print_art(art, width, height);

  free(art);

  return 0;
}