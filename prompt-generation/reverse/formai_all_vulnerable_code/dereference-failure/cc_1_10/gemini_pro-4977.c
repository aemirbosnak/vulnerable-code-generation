//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define PASSWORD_LENGTH 12
#define NUMBER_OF_PASSWORDS 5

// Arrays of possible characters
char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()";

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to generate a random character from a given array
char generateRandomCharacter(char *array) {
  int index = generateRandomNumber(0, strlen(array) - 1);
  return array[index];
}

// Function to generate a random password
char *generatePassword() {
  // Create a buffer to store the password
  char *password = malloc(PASSWORD_LENGTH + 1);

  // Generate the password
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    int type = generateRandomNumber(0, 3);
    switch (type) {
      case 0:
        password[i] = generateRandomCharacter(lowercaseLetters);
        break;
      case 1:
        password[i] = generateRandomCharacter(uppercaseLetters);
        break;
      case 2:
        password[i] = generateRandomCharacter(numbers);
        break;
      case 3:
        password[i] = generateRandomCharacter(symbols);
        break;
    }
  }

  // Terminate the string
  password[PASSWORD_LENGTH] = '\0';

  // Return the password
  return password;
}

// Function to print a list of passwords
void printPasswords(char **passwords, int numberOfPasswords) {
  for (int i = 0; i < numberOfPasswords; i++) {
    printf("Password %d: %s\n", i + 1, passwords[i]);
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a list of passwords
  char **passwords = malloc(NUMBER_OF_PASSWORDS * sizeof(char *));
  for (int i = 0; i < NUMBER_OF_PASSWORDS; i++) {
    passwords[i] = generatePassword();
  }

  // Print the list of passwords
  printPasswords(passwords, NUMBER_OF_PASSWORDS);

  // Free the memory allocated for the passwords
  for (int i = 0; i < NUMBER_OF_PASSWORDS; i++) {
    free(passwords[i]);
  }
  free(passwords);

  return 0;
}