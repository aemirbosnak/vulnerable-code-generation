//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <password>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int strength = 0;
  char *password = argv[1];

  // Check password length
  if (strlen(password) < 8) {
    printf("Password is too short (less than 8 characters).\n");
    return EXIT_FAILURE;
  } else if (strlen(password) > 64) {
    printf("Password is too long (more than 64 characters).\n");
    return EXIT_FAILURE;
  } else {
    strength += 1;
  }

  // Check password for uppercase and lowercase letters
  int has_uppercase = 0;
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
    }
  }
  if (has_uppercase && has_lowercase) {
    strength += 1;
  }

  // Check password for numbers
  int has_number = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_number = 1;
    }
  }
  if (has_number) {
    strength += 1;
  }

  // Check password for special characters
  int has_special_character = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!((password[i] >= 'a' && password[i] <= 'z') ||
          (password[i] >= 'A' && password[i] <= 'Z') ||
          (password[i] >= '0' && password[i] <= '9'))) {
      has_special_character = 1;
    }
  }
  if (has_special_character) {
    strength += 1;
  }

  // Print password strength
  switch (strength) {
    case 1:
      printf("Password strength: Weak\n");
      break;
    case 2:
      printf("Password strength: Moderate\n");
      break;
    case 3:
      printf("Password strength: Strong\n");
      break;
    case 4:
      printf("Password strength: Excellent\n");
      break;
  }

  return EXIT_SUCCESS;
}