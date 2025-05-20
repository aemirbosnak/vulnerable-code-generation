//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define PASSWORD_LENGTH 16
#define NUMBER_OF_CHARACTERS 62

// Character set
const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Function to generate a random password
char *generate_password()
{
  // Allocate memory for the password
  char *password = malloc(PASSWORD_LENGTH + 1);

  // Seed the random number generator
  srand(time(NULL));

  // Generate the password
  for (int i = 0; i < PASSWORD_LENGTH; i++)
  {
    // Get a random index into the character set
    int index = rand() % NUMBER_OF_CHARACTERS;

    // Get the character at the random index
    char character = characters[index];

    // Add the character to the password
    password[i] = character;
  }

  // Terminate the password with a null character
  password[PASSWORD_LENGTH] = '\0';

  // Return the password
  return password;
}

// Main function
int main()
{
  // Generate a random password
  char *password = generate_password();

  // Print the password
  printf("Your new password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}