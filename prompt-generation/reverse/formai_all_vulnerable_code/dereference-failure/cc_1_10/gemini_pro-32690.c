//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Define the background color codes
#define BLACK_BG "\033[40m"
#define RED_BG "\033[41m"
#define GREEN_BG "\033[42m"
#define YELLOW_BG "\033[43m"
#define BLUE_BG "\033[44m"
#define MAGENTA_BG "\033[45m"
#define CYAN_BG "\033[46m"
#define WHITE_BG "\033[47m"

// Define the reset code
#define RESET "\033[0m"

// Define the function to convert a color code to a string
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

// Define the function to convert a string to a color code
int string_to_color_code(char *string) {
  if (strcmp(string, BLACK) == 0) {
    return 0;
  } else if (strcmp(string, RED) == 0) {
    return 1;
  } else if (strcmp(string, GREEN) == 0) {
    return 2;
  } else if (strcmp(string, YELLOW) == 0) {
    return 3;
  } else if (strcmp(string, BLUE) == 0) {
    return 4;
  } else if (strcmp(string, MAGENTA) == 0) {
    return 5;
  } else if (strcmp(string, CYAN) == 0) {
    return 6;
  } else if (strcmp(string, WHITE) == 0) {
    return 7;
  } else {
    return -1;
  }
}

// Define the main function
int main() {
  // Get the input string
  char *input_string = malloc(100);
  printf("Enter the input string: ");
  scanf("%s", input_string);

  // Convert the input string to a color code
  int color_code = string_to_color_code(input_string);

  // Print the color code
  printf("The color code is: %d\n", color_code);

  // Convert the color code to a string
  char *color_string = color_code_to_string(color_code);

  // Print the color string
  printf("The color string is: %s\n", color_string);

  return 0;
}