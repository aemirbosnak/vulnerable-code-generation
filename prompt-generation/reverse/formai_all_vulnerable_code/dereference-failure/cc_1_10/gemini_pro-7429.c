//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 10

// Function to generate a random character
char generateRandomCharacter() {
  // Get a random number between 33 and 126
  int randomNumber = rand() % 94 + 33;

  // If the random number is between 33 and 47, or between 58 and 64, or between 91 and 96, then generate a new random number
  while ((randomNumber >= 33 && randomNumber <= 47) || (randomNumber >= 58 && randomNumber <= 64) || (randomNumber >= 91 && randomNumber <= 96)) {
    randomNumber = rand() % 94 + 33;
  }

  // Return the random character
  return (char)randomNumber;
}

// Function to generate a random password
char *generateRandomPassword() {
  // Allocate memory for the password
  char *password = malloc(PASSWORD_LENGTH + 1);

  // Generate a random password
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    password[i] = generateRandomCharacter();
  }

  // Terminate the password with a null character
  password[PASSWORD_LENGTH] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Generate a random password
  char *password = generateRandomPassword();

  // Print the password
  printf("Your randomly generated password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}