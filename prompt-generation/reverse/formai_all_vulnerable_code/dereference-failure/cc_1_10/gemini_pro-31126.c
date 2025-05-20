//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize a string
char *sanitize_string(char *str) {
  // Allocate memory for the sanitized string
  char *sanitized_str = malloc(strlen(str) + 1);
  if (sanitized_str == NULL) {
    return NULL;
  }

  // Initialize the sanitized string to empty
  sanitized_str[0] = '\0';

  // Iterate over the input string and append each character to the sanitized string
  // if it is a valid character
  for (int i = 0; i < strlen(str); i++) {
    char c = str[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ' || c == '.' || c == ',') {
      strncat(sanitized_str, &c, 1);
    }
  }

  // Return the sanitized string
  return sanitized_str;
}

// Function to sanitize an integer
int sanitize_int(char *str) {
  // Check if the string is empty or contains non-numeric characters
  if (strlen(str) == 0 || !isdigit(str[0])) {
    return -1;
  }

  // Convert the string to an integer
  int num = atoi(str);

  // Return the integer
  return num;
}

// Function to sanitize a float
float sanitize_float(char *str) {
  // Check if the string is empty or contains non-numeric characters
  if (strlen(str) == 0 || !isdigit(str[0]) && str[0] != '.') {
    return -1.0;
  }

  // Convert the string to a float
  float num = atof(str);

  // Return the float
  return num;
}

// Function to sanitize a user input
int main() {
  // Get the user input
  char *name = malloc(100);
  int age = -1;
  float height = -1.0;
  printf("Enter your name: ");
  scanf("%s", name);
  printf("Enter your age: ");
  scanf("%s", name);
  printf("Enter your height: ");
  scanf("%s", name);

  // Sanitize the user input
  char *sanitized_name = sanitize_string(name);
  int sanitized_age = sanitize_int(name);
  float sanitized_height = sanitize_float(name);

  // Print the sanitized user input
  printf("Sanitized name: %s\n", sanitized_name);
  printf("Sanitized age: %d\n", sanitized_age);
  printf("Sanitized height: %.2f\n", sanitized_height);

  // Free the allocated memory
  free(name);
  free(sanitized_name);

  return 0;
}