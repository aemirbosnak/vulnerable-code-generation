//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

// Define the reset code
#define RESET "\x1B[0m"

// Define the function to convert a string to a color code
int color_code_to_int(char *color) {
  if (strcmp(color, "BLACK") == 0) {
    return 30;
  } else if (strcmp(color, "RED") == 0) {
    return 31;
  } else if (strcmp(color, "GREEN") == 0) {
    return 32;
  } else if (strcmp(color, "YELLOW") == 0) {
    return 33;
  } else if (strcmp(color, "BLUE") == 0) {
    return 34;
  } else if (strcmp(color, "MAGENTA") == 0) {
    return 35;
  } else if (strcmp(color, "CYAN") == 0) {
    return 36;
  } else if (strcmp(color, "WHITE") == 0) {
    return 37;
  } else {
    return -1;
  }
}

// Define the function to convert a color code to a string
char *color_code_to_string(int color_code) {
  switch (color_code) {
  case 30:
    return "BLACK";
  case 31:
    return "RED";
  case 32:
    return "GREEN";
  case 33:
    return "YELLOW";
  case 34:
    return "BLUE";
  case 35:
    return "MAGENTA";
  case 36:
    return "CYAN";
  case 37:
    return "WHITE";
  default:
    return NULL;
  }
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a color
  if (argc < 2) {
    printf("Usage: %s <color>\n", argv[0]);
    return 1;
  }

  // Get the color from the user
  char *color = argv[1];

  // Convert the color to a color code
  int color_code = color_code_to_int(color);

  // Check if the color is valid
  if (color_code == -1) {
    printf("Invalid color: %s\n", color);
    return 1;
  }

  // Print the color code
  printf("%d\n", color_code);

  // Print the color in the specified color
  printf("%s%s%s\n", color_code_to_string(color_code), color, RESET);

  return 0;
}