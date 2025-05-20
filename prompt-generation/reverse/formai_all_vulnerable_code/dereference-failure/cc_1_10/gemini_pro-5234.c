//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16

// Function to generate a random character
char generate_random_char() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random number between 33 and 126
  int random_number = rand() % (126 - 33 + 1) + 33;

  // Convert the random number to a character and return it
  return (char)random_number;
}

// Function to generate a random password
char *generate_random_password() {
  // Allocate memory for the password
  char *password = malloc(PASSWORD_LENGTH + 1);

  // Generate a random character for each position in the password
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    password[i] = generate_random_char();
  }

  // Terminate the password with a null character
  password[PASSWORD_LENGTH] = '\0';

  // Return the password
  return password;
}

// Function to print the password
void print_password(char *password) {
  printf("Your new password is: %s\n", password);
}

int main() {
  // Generate a random password
  char *password = generate_random_password();

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}