//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()_-+=[{]};:<>,.?";

// Function to generate a random character from a given set
char random_char(char *set) {
  return set[rand() % strlen(set)];
}

// Function to generate a random password of a given length
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Initialize the password with random characters
  for (int i = 0; i < length; i++) {
    password[i] = random_char(lowercase);
  }

  // Add a random uppercase character
  password[rand() % length] = random_char(uppercase);

  // Add a random digit
  password[rand() % length] = random_char(digits);

  // Add a random symbol
  password[rand() % length] = random_char(symbols);

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the password from the user
  int length;
  printf("Enter the length of the password you want to generate: ");
  scanf("%d", &length);

  // Generate a random password
  char *password = generate_password(length);

  // Print the password
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}