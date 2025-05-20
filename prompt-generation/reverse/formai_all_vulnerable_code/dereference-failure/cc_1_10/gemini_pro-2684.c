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

// Define the reset code
#define RESET "\033[0m"

// Get the input string from the user
char *get_input_string() {
  char *input_string = NULL;
  size_t input_string_size = 0;
  getline(&input_string, &input_string_size, stdin);
  return input_string;
}

// Convert the input string to color codes
char *convert_string_to_color_codes(char *input_string) {
  // Allocate memory for the output string
  char *output_string = malloc(strlen(input_string) * 10);
  if (output_string == NULL) {
    return NULL;
  }

  // Convert each character in the input string to a color code
  int i = 0;
  while (input_string[i] != '\0') {
    switch (input_string[i]) {
      case 'a':
      case 'A':
        strcat(output_string, BLACK);
        break;
      case 'b':
      case 'B':
        strcat(output_string, RED);
        break;
      case 'c':
      case 'C':
        strcat(output_string, GREEN);
        break;
      case 'd':
      case 'D':
        strcat(output_string, YELLOW);
        break;
      case 'e':
      case 'E':
        strcat(output_string, BLUE);
        break;
      case 'f':
      case 'F':
        strcat(output_string, MAGENTA);
        break;
      case 'g':
      case 'G':
        strcat(output_string, CYAN);
        break;
      case 'h':
      case 'H':
        strcat(output_string, WHITE);
        break;
      default:
        strcat(output_string, RESET);
        break;
    }
    i++;
  }

  // Append the reset code to the output string
  strcat(output_string, RESET);

  // Return the output string
  return output_string;
}

// Print the output string to the console
void print_output_string(char *output_string) {
  printf("%s", output_string);
}

// Free the allocated memory
void free_memory(char *input_string, char *output_string) {
  free(input_string);
  free(output_string);
}

// Main function
int main() {
  // Get the input string from the user
  char *input_string = get_input_string();

  // Convert the input string to color codes
  char *output_string = convert_string_to_color_codes(input_string);

  // Print the output string to the console
  print_output_string(output_string);

  // Free the allocated memory
  free_memory(input_string, output_string);

  return 0;
}