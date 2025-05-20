//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_int(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to generate a random character from the given string
char rand_char(const char* str) {
  return str[rand_int(0, strlen(str) - 1)];
}

// Function to generate a random password of the given length
char* generate_password(int length) {
  char* password = malloc(length + 1);

  for (int i = 0; i < length; i++) {
    // Generate a random character from the given string
    char c = rand_char("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()");

    // Add the character to the password
    password[i] = c;
  }

  // Terminate the string with a null character
  password[length] = '\0';

  return password;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the password from the user
  int length;
  printf("Enter the length of the password: ");
  scanf("%d", &length);

  // Generate a random password
  char* password = generate_password(length);

  // Print the password
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}