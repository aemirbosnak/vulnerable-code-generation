//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character set for the passwords
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"

// Function to generate a random password
char *generatePassword(int length)
{
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Seed the random number generator
  srand(time(NULL));

  // Generate the password
  for (int i = 0; i < length; i++)
  {
    // Get a random character from the character set
    int index = rand() % (sizeof(CHARSET) - 1);
    char character = CHARSET[index];

    // Add the character to the password
    password[i] = character;
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Function to test the password generator
int main()
{
  // Get the password length from the user
  int length;
  printf("Enter the desired password length: ");
  scanf("%d", &length);

  // Generate a random password
  char *password = generatePassword(length);

  // Print the password
  printf("Here is your password: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}