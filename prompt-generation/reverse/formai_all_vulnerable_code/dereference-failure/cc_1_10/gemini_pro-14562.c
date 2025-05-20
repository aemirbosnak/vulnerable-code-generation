//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
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
int main() {
  // Get the input string from the user
  char *input = NULL;
  size_t len = 0;
  printf("Enter a string: ");
  getline(&input, &len, stdin);

  // Convert the input string to uppercase
  for (int i = 0; i < strlen(input); i++) {
    input[i] = toupper(input[i]);
  }

  // Iterate over the input string and print each character in a different color
  for (int i = 0; i < strlen(input); i++) {
    switch (input[i]) {
      case 'A':
        printf(RED "%c" RESET, input[i]);
        break;
      case 'B':
        printf(GREEN "%c" RESET, input[i]);
        break;
      case 'C':
        printf(YELLOW "%c" RESET, input[i]);
        break;
      case 'D':
        printf(BLUE "%c" RESET, input[i]);
        break;
      case 'E':
        printf(MAGENTA "%c" RESET, input[i]);
        break;
      case 'F':
        printf(CYAN "%c" RESET, input[i]);
        break;
      case 'G':
        printf(WHITE "%c" RESET, input[i]);
        break;
      default:
        printf("%c", input[i]);
        break;
    }
  }

  // Print a newline character
  printf("\n");

  // Free the input string
  free(input);

  // Return 0 to indicate success
  return 0;
}