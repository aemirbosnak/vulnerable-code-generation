//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character set for the password
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"

// Get the length of the password from the user
int get_password_length() {
  int length;
  printf("Enter the desired length of the password: ");
  scanf("%d", &length);
  return length;
}

// Generate a random password
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Seed the random number generator
  srand(time(NULL));

  // Generate a random password
  for (int i = 0; i < length; i++) {
    password[i] = CHARSET[rand() % strlen(CHARSET)];
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Print the password to the console
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
  free(password);
}

// Main function
int main() {
  // Get the length of the password from the user
  int length = get_password_length();

  // Generate a random password
  char *password = generate_password(length);

  // Print the password to the console
  print_password(password);

  // Free the memory allocated for the password
  free_password(password);

  return 0;
}