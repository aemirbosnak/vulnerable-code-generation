//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define DEFAULT "\x1b[0m"

// Define the color conversion function
char *color_convert(char *color) {
  // Convert the color to lowercase
  char *lower = strdup(color);
  for (int i = 0; lower[i] != '\0'; i++) {
    lower[i] = tolower(lower[i]);
  }

  // Return the corresponding color code
  if (strcmp(lower, "black") == 0) {
    return BLACK;
  } else if (strcmp(lower, "red") == 0) {
    return RED;
  } else if (strcmp(lower, "green") == 0) {
    return GREEN;
  } else if (strcmp(lower, "yellow") == 0) {
    return YELLOW;
  } else if (strcmp(lower, "blue") == 0) {
    return BLUE;
  } else if (strcmp(lower, "magenta") == 0) {
    return MAGENTA;
  } else if (strcmp(lower, "cyan") == 0) {
    return CYAN;
  } else if (strcmp(lower, "white") == 0) {
    return WHITE;
  } else {
    return DEFAULT;
  }
}

// Define the main function
int main() {
  // Get the color from the user
  char color[100];
  printf("Enter a color: ");
  scanf("%s", color);

  // Convert the color to the corresponding color code
  char *colorCode = color_convert(color);

  // Print the color in the corresponding color code
  printf("The color code for %s is %s%s%s\n", color, colorCode, color, DEFAULT);

  return 0;
}