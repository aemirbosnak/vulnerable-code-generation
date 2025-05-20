//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets used for password generation
#define LOWERCASE_CHAR_SET "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGIT_CHAR_SET "0123456789"
#define SYMBOL_CHAR_SET "!@#$%^&*()_-+={[}]|\:;<>,.?/"

// Get a random number within a specified range
int get_random_number(int min, int max) {
  return min + (rand() % (max - min + 1));
}

// Generate a random character from a given character set
char get_random_character(const char *char_set) {
  int index = get_random_number(0, strlen(char_set) - 1);
  return char_set[index];
}

// Generate a password of a specified length using the given character sets
char *generate_password(int length, const char *char_sets[]) {
  // Allocate memory for the password
  char *password = malloc(length + 1);
  if (password == NULL) {
    return NULL;
  }

  // Generate a random password character by character
  for (int i = 0; i < length; i++) {
    int char_set_index = get_random_number(0, sizeof(char_sets) / sizeof(char *) - 1);
    char character = get_random_character(char_sets[char_set_index]);
    password[i] = character;
  }

  // Terminate the password string with a null character
  password[length] = '\0';

  // Return the generated password
  return password;
}

// Print the generated password to the console
void print_password(const char *password) {
  printf("Generated password: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
  free(password);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Define the character sets to use for password generation
  const char *char_sets[] = {LOWERCASE_CHAR_SET, UPPERCASE_CHAR_SET, DIGIT_CHAR_SET, SYMBOL_CHAR_SET};

  // Get the desired password length from the user
  int password_length;
  printf("Enter the desired password length: ");
  scanf("%d", &password_length);

  // Generate a password using the specified character sets and length
  char *password = generate_password(password_length, char_sets);

  // Print the generated password to the console
  print_password(password);

  // Free the memory allocated for the password
  free_password(password);

  return 0;
}