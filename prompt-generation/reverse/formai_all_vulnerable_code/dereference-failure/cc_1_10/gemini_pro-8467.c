//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()_-+=";

// Declare the password length
int password_length = 10;

// Generate a random number within a range
int random_number(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// Generate a random character from a character set
char random_character(char *character_set) {
  int index = random_number(0, strlen(character_set) - 1);
  return character_set[index];
}

// Generate a random password
char *generate_password() {
  // Allocate memory for the password
  char *password = malloc(password_length + 1);

  // Generate the password
  for (int i = 0; i < password_length; i++) {
    int character_set_index = random_number(0, 3);

    switch (character_set_index) {
      case 0:
        password[i] = random_character(lowercase);
        break;
      case 1:
        password[i] = random_character(uppercase);
        break;
      case 2:
        password[i] = random_character(numbers);
        break;
      case 3:
        password[i] = random_character(symbols);
        break;
    }
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
  // Seed the random number generator
  srand(time(NULL));

  // Generate a password
  char *password = generate_password();

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free_password(password);

  return 0;
}