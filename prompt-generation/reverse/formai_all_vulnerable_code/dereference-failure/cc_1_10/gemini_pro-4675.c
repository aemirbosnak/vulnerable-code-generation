//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets for the password
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()";

// Get the length of the password from the user
int get_password_length() {
  int length;
  printf("Enter the desired length of the password: ");
  scanf("%d", &length);
  return length;
}

// Generate a random character from a given character set
char generate_random_character(char *charset) {
  int index = rand() % strlen(charset);
  return charset[index];
}

// Generate a secure password using the given character sets
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Initialize the password to all zeros
  memset(password, 0, length + 1);

  // Generate a random character for each position in the password
  for (int i = 0; i < length; i++) {
    int charset_index = rand() % 4;
    switch (charset_index) {
      case 0:
        password[i] = generate_random_character(lowercase);
        break;
      case 1:
        password[i] = generate_random_character(uppercase);
        break;
      case 2:
        password[i] = generate_random_character(numbers);
        break;
      case 3:
        password[i] = generate_random_character(symbols);
        break;
    }
  }

  // Return the generated password
  return password;
}

// Print the generated password to the console
void print_password(char *password) {
  printf("Your secure password is: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
  free(password);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the password from the user
  int length = get_password_length();

  // Generate a secure password
  char *password = generate_password(length);

  // Print the generated password to the console
  print_password(password);

  // Free the memory allocated for the password
  free_password(password);

  return 0;
}