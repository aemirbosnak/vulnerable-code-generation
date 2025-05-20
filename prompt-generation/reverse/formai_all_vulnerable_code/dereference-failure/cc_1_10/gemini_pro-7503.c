//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char generateCharacter() {
  int randomNumber = rand() % 94 + 33;
  return (char)randomNumber;
}

// Function to generate a random string
char *generateString(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = generateCharacter();
  }
  string[length] = '\0';
  return string;
}

// Function to generate a secure password
char *generatePassword(int length) {
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int randomNumber = rand() % 4;
    switch (randomNumber) {
      case 0:
        password[i] = generateCharacter();
        break;
      case 1:
        password[i] = generateCharacter() - 32;
        break;
      case 2:
        password[i] = (rand() % 10) + 48;
        break;
      case 3:
        password[i] = (rand() % 26) + 65;
        break;
    }
  }
  password[length] = '\0';
  return password;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the password from the user
  int length;
  printf("Enter the length of the password: ");
  scanf("%d", &length);

  // Generate a secure password
  char *password = generatePassword(length);

  // Print the password to the console
  printf("Your secure password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}