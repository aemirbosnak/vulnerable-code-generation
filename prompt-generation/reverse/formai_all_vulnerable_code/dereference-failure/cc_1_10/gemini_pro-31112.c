//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digit(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string is a valid name
int is_name(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (!isalpha(str[i]) && str[i] != ' ') {
      return 0;
    }
  }
  return 1;
}

int main() {
  char *name;
  char *age;

  // Get the user's name
  printf("Enter your name: ");
  scanf(" %ms", &name);

  // Validate the user's name
  while (!is_name(name)) {
    printf("Invalid name. Please enter a valid name: ");
    scanf(" %ms", &name);
  }

  // Get the user's age
  printf("Enter your age: ");
  scanf(" %ms", &age);

  // Validate the user's age
  while (!is_digit(age)) {
    printf("Invalid age. Please enter a valid age: ");
    scanf(" %ms", &age);
  }

  // Print the user's information
  printf("Your name is %s and your age is %s.\n", name, age);

  // Free the allocated memory
  free(name);
  free(age);

  return 0;
}