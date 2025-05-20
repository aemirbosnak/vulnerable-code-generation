//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *password;
  int password_length;

  // Allocate memory for the password
  password = malloc(100);

  // Get the password from the user
  printf("Enter a password: ");
  fgets(password, 100, stdin);

  // Remove the newline character from the password
  password_length = strlen(password);
  if (password_length > 0 && password[password_length - 1] == '\n') {
    password[password_length - 1] = '\0';
  }

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength
  switch (strength) {
    case 0:
      printf("Password strength: Weak\n");
      break;
    case 1:
      printf("Password strength: Moderate\n");
      break;
    case 2:
      printf("Password strength: Strong\n");
      break;
    case 3:
      printf("Password strength: Very strong\n");
      break;
  }

  // Free the memory allocated for the password
  free(password);

  return 0;
}

int check_password_strength(char *password) {
  int length = strlen(password);
  int has_numbers = 0;
  int has_letters = 0;
  int has_symbols = 0;

  // Check for numbers
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_numbers = 1;
    }
  }

  // Check for letters
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_letters = 1;
    }
  }

  // Check for symbols
  for (int i = 0; i < length; i++) {
    if (password[i] >= '!' && password[i] <= '~') {
      has_symbols = 1;
    }
  }

  // Calculate the password strength
  int strength = 0;
  if (has_numbers) {
    strength++;
  }
  if (has_letters) {
    strength++;
  }
  if (has_symbols) {
    strength++;
  }

  return strength;
}