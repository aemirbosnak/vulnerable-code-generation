//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_PASSWORD_LENGTH 128
#define MIN_PASSWORD_LENGTH 8

// Function to generate a random character
char generate_random_character() {
  // Generate a random number between 33 and 126
  int random_number = rand() % (126 - 33 + 1) + 33;

  // Return the corresponding character
  return (char)random_number;
}

// Function to generate a password
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Generate a random character for each position in the password
  for (int i = 0; i < length; i++) {
    password[i] = generate_random_character();
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Function to check if a password is valid
int is_password_valid(char *password) {
  // Check if the password is at least the minimum length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return 0;
  }

  // Check if the password contains at least one uppercase letter
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase) {
    return 0;
  }

  // Check if the password contains at least one lowercase letter
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase) {
    return 0;
  }

  // Check if the password contains at least one digit
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit) {
    return 0;
  }

  // Check if the password contains at least one special character
  int has_special_character = 0;
  for (int i = 0; i < strlen(password); i++) {
    if ((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126)) {
      has_special_character = 1;
      break;
    }
  }
  if (!has_special_character) {
    return 0;
  }

  // The password is valid
  return 1;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a password
  char *password = generate_password(MAX_PASSWORD_LENGTH);

  // Check if the password is valid
  int is_valid = is_password_valid(password);

  // Print the password
  if (is_valid) {
    printf("The generated password is: %s\n", password);
  } else {
    printf("The generated password is not valid.\n");
  }

  // Free the memory allocated for the password
  free(password);

  return 0;
}