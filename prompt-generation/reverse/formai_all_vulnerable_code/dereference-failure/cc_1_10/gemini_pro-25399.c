//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()_+=-?";

// Generate a random number between min and max
int random_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Generate a random character from a character set
char random_char(char *charset) {
  return charset[random_range(0, strlen(charset) - 1)];
}

// Generate a random password of a given length
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Generate a random character for each position in the password
  for (int i = 0; i < length; i++) {
    // Choose a random character set
    int charset_index = random_range(0, 3);
    char *charset;
    switch (charset_index) {
      case 0:
        charset = lowercase;
        break;
      case 1:
        charset = uppercase;
        break;
      case 2:
        charset = numbers;
        break;
      case 3:
        charset = symbols;
        break;
    }

    // Generate a random character from the chosen character set
    password[i] = random_char(charset);
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

  // Get the password length from the user
  int length;
  printf("Enter the password length: ");
  scanf("%d", &length);

  // Generate a random password
  char *password = generate_password(length);

  // Print the password
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}