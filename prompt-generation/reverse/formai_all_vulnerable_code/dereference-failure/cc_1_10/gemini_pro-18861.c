//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_numeric(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] < '0' || str[i] > '9') {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string is a valid real number
int is_real(char *str) {
  int decimal_point_count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] < '0' || str[i] > '9') {
      if (str[i] == '.' && decimal_point_count == 0) {
        decimal_point_count++;
      } else {
        return 0;
      }
    }
  }
  return 1;
}

// Function to sanitize a string
char *sanitize_string(char *str) {
  // Remove leading and trailing whitespace
  while (*str == ' ') {
    str++;
  }
  while (*(str + strlen(str) - 1) == ' ') {
    *(str + strlen(str) - 1) = '\0';
  }

  // Remove any special characters
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] < '0' || str[i] > '9') {
      if (str[i] != '.' && str[i] != '-') {
        str[i] = ' ';
      }
    }
  }

  // Remove any consecutive spaces
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ' && str[i + 1] == ' ') {
      for (int j = i; str[j] != '\0'; j++) {
        str[j] = str[j + 1];
      }
      i--;
    }
  }

  return str;
}

int main() {
  char input[1024];

  // Get input from the user
  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);

  // Sanitize the input string
  char *sanitized_input = sanitize_string(input);

  // Check if the input is a number
  if (is_numeric(sanitized_input)) {
    printf("The input is a number.\n");
  } else if (is_real(sanitized_input)) {
    printf("The input is a real number.\n");
  } else {
    printf("The input is not a number.\n");
  }

  return 0;
}