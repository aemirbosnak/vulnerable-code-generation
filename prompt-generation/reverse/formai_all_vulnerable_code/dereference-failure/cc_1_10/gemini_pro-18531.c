//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: curious
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

// Define the function to convert a color code to a string
char* color_code_to_string(char* color_code) {
  if (strcmp(color_code, BLACK) == 0) {
    return "BLACK";
  } else if (strcmp(color_code, RED) == 0) {
    return "RED";
  } else if (strcmp(color_code, GREEN) == 0) {
    return "GREEN";
  } else if (strcmp(color_code, YELLOW) == 0) {
    return "YELLOW";
  } else if (strcmp(color_code, BLUE) == 0) {
    return "BLUE";
  } else if (strcmp(color_code, MAGENTA) == 0) {
    return "MAGENTA";
  } else if (strcmp(color_code, CYAN) == 0) {
    return "CYAN";
  } else if (strcmp(color_code, WHITE) == 0) {
    return "WHITE";
  } else {
    return "INVALID COLOR CODE";
  }
}

// Define the function to convert a string to a color code
char* string_to_color_code(char* color_string) {
  if (strcmp(color_string, "BLACK") == 0) {
    return BLACK;
  } else if (strcmp(color_string, "RED") == 0) {
    return RED;
  } else if (strcmp(color_string, "GREEN") == 0) {
    return GREEN;
  } else if (strcmp(color_string, "YELLOW") == 0) {
    return YELLOW;
  } else if (strcmp(color_string, "BLUE") == 0) {
    return BLUE;
  } else if (strcmp(color_string, "MAGENTA") == 0) {
    return MAGENTA;
  } else if (strcmp(color_string, "CYAN") == 0) {
    return CYAN;
  } else if (strcmp(color_string, "WHITE") == 0) {
    return WHITE;
  } else {
    return "INVALID COLOR STRING";
  }
}

// Define the main function
int main() {
  // Get the color code from the user
  char* color_code = (char*)malloc(sizeof(char) * 10);
  printf("Enter a color code (e.g., BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE): ");
  scanf("%s", color_code);

  // Convert the color code to a string
  char* color_string = color_code_to_string(color_code);

  // Print the color string
  printf("The color code %s corresponds to the color string %s.\n", color_code, color_string);

  // Free the memory allocated for the color code
  free(color_code);

  return 0;
}