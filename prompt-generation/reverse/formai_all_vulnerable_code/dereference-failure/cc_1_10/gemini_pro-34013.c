//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 16

// Function to generate a random character
char generateRandomChar() {
  // Get a random number between 33 and 126
  int randomNumber = rand() % (126 - 33) + 33;

  // Convert the random number to a character
  char randomChar = (char)randomNumber;

  // Return the random character
  return randomChar;
}

// Function to generate a secure password
char *generateSecurePassword() {
  // Allocate memory for the password
  char *password = malloc(PASSWORD_LENGTH + 1);

  // Generate a random password
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    password[i] = generateRandomChar();
  }

  // Terminate the password with a null character
  password[PASSWORD_LENGTH] = '\0';

  // Return the password
  return password;
}

// Function to print the password
void printPassword(char *password) {
  // Print the password
  printf("Your password is: %s\n", password);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a secure password
  char *password = generateSecurePassword();

  // Print the password
  printPassword(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}