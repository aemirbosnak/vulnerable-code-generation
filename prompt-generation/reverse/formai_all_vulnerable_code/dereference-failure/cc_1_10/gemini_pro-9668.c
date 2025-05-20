//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets to be used in the password
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()_+";

// Define the length of the password to be generated
#define PASSWORD_LENGTH 16

// Function to generate a random number within a given range
int rand_range(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to generate a random character from a given character set
char rand_char(char *charset) {
  int index = rand_range(0, strlen(charset) - 1);
  return charset[index];
}

// Function to generate a random password
char *generate_password() {
  // Allocate memory for the password
  char *password = malloc(PASSWORD_LENGTH + 1);

  // Generate a random character from each character set
  password[0] = rand_char(lowercase);
  password[1] = rand_char(uppercase);
  password[2] = rand_char(digits);
  password[3] = rand_char(symbols);

  // Generate the remaining characters randomly from all character sets
  for (int i = 4; i < PASSWORD_LENGTH; i++) {
    int charset_index = rand_range(0, 3);
    char *charset;
    switch (charset_index) {
      case 0:
        charset = lowercase;
        break;
      case 1:
        charset = uppercase;
        break;
      case 2:
        charset = digits;
        break;
      case 3:
        charset = symbols;
        break;
    }
    password[i] = rand_char(charset);
  }

  // Null-terminate the password string
  password[PASSWORD_LENGTH] = '\0';

  // Return the generated password
  return password;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random password
  char *password = generate_password();

  // Print the generated password to the console
  printf("Generated password: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}