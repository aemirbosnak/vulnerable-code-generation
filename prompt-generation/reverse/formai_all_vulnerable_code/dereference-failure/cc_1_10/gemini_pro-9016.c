//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character set for the password
char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Define the length of the password
int password_length = 16;

// Generate a random password
char *generate_password() {
  // Allocate memory for the password
  char *password = malloc(password_length + 1);

  // Seed the random number generator
  srand(time(NULL));

  // Generate each character of the password
  for (int i = 0; i < password_length; i++) {
    // Get a random index into the character set
    int index = rand() % (sizeof(charset) - 1);

    // Get the character at the random index
    char character = charset[index];

    // Add the character to the password
    password[i] = character;
  }

  // Terminate the password with a null character
  password[password_length] = '\0';

  // Return the password
  return password;
}

// Print the password
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
  free(password);
}

// Main function
int main() {
  // Generate a password
  char *password = generate_password();

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free_password(password);

  return 0;
}