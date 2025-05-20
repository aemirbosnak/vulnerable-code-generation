//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets for the password
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()";

// Define the length of the password
#define PASSWORD_LENGTH 16

// Generate a random number between min and max
int random_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Generate a random character from a given set
char random_char(char *set) {
  return set[random_range(0, strlen(set) - 1)];
}

// Generate a random password
char *generate_password() {
  // Allocate memory for the password
  char *password = malloc(PASSWORD_LENGTH + 1);

  // Generate a random character from each character set
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    int set_index = random_range(0, 3);
    switch (set_index) {
      case 0:
        password[i] = random_char(lowercase);
        break;
      case 1:
        password[i] = random_char(uppercase);
        break;
      case 2:
        password[i] = random_char(digits);
        break;
      case 3:
        password[i] = random_char(symbols);
        break;
    }
  }

  // Terminate the password with a null character
  password[PASSWORD_LENGTH] = '\0';

  // Return the password
  return password;
}

// Print the password to the console
void print_password(char *password) {
  printf("Your randomly generated password is: %s\n", password);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random password
  char *password = generate_password();

  // Print the password to the console
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}