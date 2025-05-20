//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 16

// Function to generate a random character from the given character set
char generate_random_character(char *character_set) {
  int index = rand() % strlen(character_set);
  return character_set[index];
}

// Function to generate a random password
char *generate_password() {
  // Define the character set for the password
  char character_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

  // Allocate memory for the password
  char *password = malloc(PASSWORD_LENGTH + 1);

  // Generate the password
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    password[i] = generate_random_character(character_set);
  }

  // Terminate the password with a null character
  password[PASSWORD_LENGTH] = '\0';

  // Return the password
  return password;
}

// Function to print the password
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random password
  char *password = generate_password();

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}