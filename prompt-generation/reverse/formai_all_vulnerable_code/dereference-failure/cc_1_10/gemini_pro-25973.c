//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style
#define DEBUG 1

// Color code constants
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

// Reset color code
#define RESET   "\033[0m"

// Function to convert a color name to its code
char *color_code(char *color) {
  if (strcmp(color, "black") == 0) {
    return BLACK;
  } else if (strcmp(color, "red") == 0) {
    return RED;
  } else if (strcmp(color, "green") == 0) {
    return GREEN;
  } else if (strcmp(color, "yellow") == 0) {
    return YELLOW;
  } else if (strcmp(color, "blue") == 0) {
    return BLUE;
  } else if (strcmp(color, "magenta") == 0) {
    return MAGENTA;
  } else if (strcmp(color, "cyan") == 0) {
    return CYAN;
  } else if (strcmp(color, "white") == 0) {
    return WHITE;
  } else {
    return RESET;
  }
}

// Function to print a string in a specified color
void print_color(char *color, char *string) {
  printf("%s%s%s", color_code(color), string, RESET);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user specified a color
  if (argc < 2) {
    printf("Usage: %s <color> <string>\n", argv[0]);
    return 1;
  }

  // Get the color and string from the command line
  char *color = argv[1];
  char *string = argv[2];

  // Print the string in the specified color
  print_color(color, string);

  // Print a newline
  printf("\n");

  return 0;
}