//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets for the password
#define CHARSET_LOWER "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_DIGITS "0123456789"
#define CHARSET_SYMBOLS "!@#$%^&*()_+"

// Get the length of the password from the user
int get_password_length() {
  int length;
  printf("Enter the desired password length: ");
  scanf("%d", &length);
  return length;
}

// Get the character set from the user
char *get_character_set() {
  int choice;
  printf("Select a character set:\n");
  printf("1. Lowercase letters\n");
  printf("2. Uppercase letters\n");
  printf("3. Digits\n");
  printf("4. Symbols\n");
  printf("5. All of the above\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      return CHARSET_LOWER;
    case 2:
      return CHARSET_UPPER;
    case 3:
      return CHARSET_DIGITS;
    case 4:
      return CHARSET_SYMBOLS;
    case 5:
      return CHARSET_LOWER CHARSET_UPPER CHARSET_DIGITS CHARSET_SYMBOLS;
    default:
      printf("Invalid choice. Defaulting to lowercase letters.\n");
      return CHARSET_LOWER;
  }
}

// Generate a random password
char *generate_password(int length, char *charset) {
  char *password = malloc(length + 1);  // +1 for the null terminator
  for (int i = 0; i < length; i++) {
    int index = rand() % strlen(charset);
    password[i] = charset[index];
  }
  password[length] = '\0';  // Null-terminate the password
  return password;
}

// Print the generated password
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

// Free the allocated memory
void free_password(char *password) {
  free(password);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the password length from the user
  int length = get_password_length();

  // Get the character set from the user
  char *charset = get_character_set();

  // Generate a password
  char *password = generate_password(length, charset);

  // Print the password
  print_password(password);

  // Free the allocated memory
  free_password(password);

  return 0;
}