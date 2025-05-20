//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: innovative
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

// Define the reset code
#define RESET "\033[0m"

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a color code
  if (argc < 2) {
    printf("Usage: %s <color code>\n", argv[0]);
    return 1;
  }

  // Get the color code from the user
  char *color_code = argv[1];

  // Convert the color code to a string
  char *color_string;
  if (strcmp(color_code, "black") == 0) {
    color_string = BLACK;
  } else if (strcmp(color_code, "red") == 0) {
    color_string = RED;
  } else if (strcmp(color_code, "green") == 0) {
    color_string = GREEN;
  } else if (strcmp(color_code, "yellow") == 0) {
    color_string = YELLOW;
  } else if (strcmp(color_code, "blue") == 0) {
    color_string = BLUE;
  } else if (strcmp(color_code, "magenta") == 0) {
    color_string = MAGENTA;
  } else if (strcmp(color_code, "cyan") == 0) {
    color_string = CYAN;
  } else if (strcmp(color_code, "white") == 0) {
    color_string = WHITE;
  } else {
    printf("Invalid color code: %s\n", color_code);
    return 1;
  }

  // Print the color string to the console
  printf("%sHello, world!%s\n", color_string, RESET);

  return 0;
}