//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Colors
#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

// Backgrounds
#define BLACK_BG "\x1B[40m"
#define RED_BG "\x1B[41m"
#define GREEN_BG "\x1B[42m"
#define YELLOW_BG "\x1B[43m"
#define BLUE_BG "\x1B[44m"
#define MAGENTA_BG "\x1B[45m"
#define CYAN_BG "\x1B[46m"
#define WHITE_BG "\x1B[47m"

// Modifiers
#define BOLD "\x1B[1m"
#define DIM "\x1B[2m"
#define ITALIC "\x1B[3m"
#define UNDERLINE "\x1B[4m"
#define BLINK "\x1B[5m"
#define INVERT "\x1B[7m"
#define HIDDEN "\x1B[8m"

// Reset
#define RESET "\x1B[0m"

// Function to convert color code to string
char *color_code_to_string(int color_code) {
  switch (color_code) {
  case 0:
    return BLACK;
  case 1:
    return RED;
  case 2:
    return GREEN;
  case 3:
    return YELLOW;
  case 4:
    return BLUE;
  case 5:
    return MAGENTA;
  case 6:
    return CYAN;
  case 7:
    return WHITE;
  default:
    return RESET;
  }
}

// Function to convert string to color code
int string_to_color_code(char *color_string) {
  if (strcmp(color_string, BLACK) == 0) {
    return 0;
  } else if (strcmp(color_string, RED) == 0) {
    return 1;
  } else if (strcmp(color_string, GREEN) == 0) {
    return 2;
  } else if (strcmp(color_string, YELLOW) == 0) {
    return 3;
  } else if (strcmp(color_string, BLUE) == 0) {
    return 4;
  } else if (strcmp(color_string, MAGENTA) == 0) {
    return 5;
  } else if (strcmp(color_string, CYAN) == 0) {
    return 6;
  } else if (strcmp(color_string, WHITE) == 0) {
    return 7;
  } else {
    return -1;
  }
}

// Function to test color code conversion
void test_color_code_conversion() {
  int color_code;
  char *color_string;

  // Convert color codes to strings
  for (color_code = 0; color_code < 8; color_code++) {
    color_string = color_code_to_string(color_code);
    printf("%d: %s\n", color_code, color_string);
  }

  // Convert strings to color codes
  for (color_string = BLACK; color_string <= WHITE; color_string++) {
    color_code = string_to_color_code(color_string);
    printf("%s: %d\n", color_string, color_code);
  }
}

// Main function
int main() {
  // Test color code conversion
  test_color_code_conversion();

  return 0;
}