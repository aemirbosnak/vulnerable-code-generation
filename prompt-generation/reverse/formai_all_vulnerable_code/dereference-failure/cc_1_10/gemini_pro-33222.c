//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets
char *lowercase = "abcdefghijklmnopqrstuvwxyz";
char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *digits = "0123456789";
char *symbols = "!@#$%^&*()_+=-`~";

// Define the function to generate a random character from a character set
char random_character(char *set) {
  int index = rand() % strlen(set);
  return set[index];
}

// Define the function to generate a random password
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);
  if (password == NULL) {
    return NULL;
  }

  // Generate the password
  for (int i = 0; i < length; i++) {
    // Choose a random character set
    int set_index = rand() % 4;
    char *set = NULL;
    switch (set_index) {
      case 0:
        set = lowercase;
        break;
      case 1:
        set = uppercase;
        break;
      case 2:
        set = digits;
        break;
      case 3:
        set = symbols;
        break;
    }

    // Generate a random character from the chosen set
    password[i] = random_character(set);
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the desired password length from the user
  int length;
  printf("Enter the desired password length: ");
  scanf("%d", &length);

  // Generate a random password
  char *password = generate_password(length);

  // Print the generated password to the console
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}