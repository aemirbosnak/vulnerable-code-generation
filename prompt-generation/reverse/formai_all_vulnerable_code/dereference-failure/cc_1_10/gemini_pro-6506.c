//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()_+=-`~";

// Define the password length
int password_length = 16;

// Generate a random number between min and max
int random_number(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Generate a random character from a character set
char random_character(char *charset) {
  int index = random_number(0, strlen(charset) - 1);
  return charset[index];
}

// Generate a random password
char *generate_password() {
  // Allocate memory for the password
  char *password = malloc(password_length + 1);

  // Initialize the password with zeroes
  memset(password, 0, password_length + 1);

  // Generate a random character from each character set
  password[0] = random_character(lowercase);
  password[1] = random_character(uppercase);
  password[2] = random_character(numbers);
  password[3] = random_character(symbols);

  // Generate the remaining characters randomly
  for (int i = 4; i < password_length; i++) {
    password[i] = random_character(lowercase);
  }

  // Return the password
  return password;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random password
  char *password = generate_password();

  // Print the password
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}