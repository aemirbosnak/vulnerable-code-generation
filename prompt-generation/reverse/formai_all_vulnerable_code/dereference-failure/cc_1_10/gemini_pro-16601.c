//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char generate_random_character() {
  // Get a random number between 33 and 126 (inclusive)
  int random_number = rand() % (126 - 33 + 1) + 33;

  // Convert the random number to a character
  char random_character = (char)random_number;

  // Return the random character
  return random_character;
}

// Function to generate a random password
char *generate_random_password(int length) {
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

// Function to test the password generator
void test_password_generator() {
  // Generate a random password of length 10
  char *password = generate_random_password(10);

  // Print the password
  printf("Generated password: %s\n", password);

  // Free the memory allocated for the password
  free(password);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Test the password generator
  test_password_generator();

  return 0;
}