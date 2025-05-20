//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char generateRandomChar() {
  // Get a random number between 0 and 255
  int randomNumber = rand() % 256;

  // Convert the random number to a character
  char randomChar = (char)randomNumber;

  // Return the random character
  return randomChar;
}

// Function to generate a random string of a given length
char *generateRandomString(int length) {
  // Allocate memory for the string
  char *randomString = malloc(length + 1);

  // Generate a random character for each position in the string
  for (int i = 0; i < length; i++) {
    randomString[i] = generateRandomChar();
  }

  // Terminate the string with a null character
  randomString[length] = '\0';

  // Return the random string
  return randomString;
}

// Function to generate a secure password of a given length
char *generateSecurePassword(int length) {
  // Generate a random string of the given length
  char *randomString = generateRandomString(length);

  // Check if the random string contains any weak characters
  int containsWeakCharacters = 0;
  for (int i = 0; i < length; i++) {
    if (randomString[i] == ' ' || randomString[i] == '\n' || randomString[i] == '\t' || randomString[i] == '\r') {
      containsWeakCharacters = 1;
      break;
    }
  }

  // If the random string contains any weak characters, generate a new random string
  if (containsWeakCharacters) {
    free(randomString);
    randomString = generateSecurePassword(length);
  }

  // Return the secure password
  return randomString;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the password from the user
  int passwordLength;
  printf("Enter the length of the password: ");
  scanf("%d", &passwordLength);

  // Generate a secure password of the given length
  char *password = generateSecurePassword(passwordLength);

  // Print the password to the console
  printf("Your secure password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}