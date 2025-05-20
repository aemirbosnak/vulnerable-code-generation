//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 64

// Function to generate a random password
char *generate_password(int length) {
  // Seed the random number generator
  srand(time(NULL));

  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Generate the password
  for (int i = 0; i < length; i++) {
    // Generate a random character
    int character = rand() % 94 + 33;

    // Make sure the character is not a space
    while (character == ' ') {
      character = rand() % 94 + 33;
    }

    // Add the character to the password
    password[i] = character;
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Function to print the password
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

// Main function
int main() {
  // Get the length of the password from the user
  int length;
  printf("Enter the length of the password you want: ");
  scanf("%d", &length);

  // Generate a password
  char *password = generate_password(length);

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}