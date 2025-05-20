//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MIN_LENGTH 8
#define MAX_LENGTH 64
#define CHARSET_SIZE 94

// Character set
char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+";

// Function to generate a random number between min and max
int random_int(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to generate a random character from the character set
char random_char() {
  return charset[random_int(0, CHARSET_SIZE - 1)];
}

// Function to generate a random password of a given length
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Generate the password
  for (int i = 0; i < length; i++) {
    password[i] = random_char();
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the desired password length from the user
  int length;
  printf("Enter the desired password length (8-64): ");
  scanf("%d", &length);

  // Validate the password length
  if (length < MIN_LENGTH || length > MAX_LENGTH) {
    printf("Invalid password length. Please enter a value between 8 and 64.\n");
    return 1;
  }

  // Generate the password
  char *password = generate_password(length);

  // Print the password
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}