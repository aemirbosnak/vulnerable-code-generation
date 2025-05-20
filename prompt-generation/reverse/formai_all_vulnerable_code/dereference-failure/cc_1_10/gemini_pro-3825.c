//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define FAIR 1
#define GOOD 2
#define STRONG 3

// Define the password requirements
#define MIN_LENGTH 8
#define MIN_NUMBERS 1
#define MIN_LETTERS 1
#define MIN_SYMBOLS 1

// Define the password scoring system
#define POINTS_PER_LETTER 1
#define POINTS_PER_NUMBER 2
#define POINTS_PER_SYMBOL 3
#define POINTS_PER_LENGTH 1

// Get the password from the user
char *get_password() {
  char *password = malloc(100);
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Check the password strength
int check_password_strength(char *password) {
  int length = strlen(password);
  int num_numbers = 0;
  int num_letters = 0;
  int num_symbols = 0;
  int score = 0;

  // Check the password length
  if (length < MIN_LENGTH) {
    printf("Your password is too short! It must be at least %d characters long.\n", MIN_LENGTH);
    return WEAK;
  }

  // Check for numbers
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      num_numbers++;
    }
  }

  if (num_numbers < MIN_NUMBERS) {
    printf("Your password must contain at least %d numbers.\n", MIN_NUMBERS);
    return WEAK;
  }

  // Check for letters
  for (int i = 0; i < length; i++) {
    if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z')) {
      num_letters++;
    }
  }

  if (num_letters < MIN_LETTERS) {
    printf("Your password must contain at least %d letters.\n", MIN_LETTERS);
    return WEAK;
  }

  // Check for symbols
  for (int i = 0; i < length; i++) {
    if (!((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9'))) {
      num_symbols++;
    }
  }

  if (num_symbols < MIN_SYMBOLS) {
    printf("Your password must contain at least %d symbols.\n", MIN_SYMBOLS);
    return WEAK;
  }

  // Calculate the password score
  score += length * POINTS_PER_LENGTH;
  score += num_letters * POINTS_PER_LETTER;
  score += num_numbers * POINTS_PER_NUMBER;
  score += num_symbols * POINTS_PER_SYMBOL;

  // Return the password strength level
  if (score < 20) {
    return WEAK;
  } else if (score < 40) {
    return FAIR;
  } else if (score < 60) {
    return GOOD;
  } else {
    return STRONG;
  }
}

// Print the password strength level
void print_password_strength(int strength) {
  switch (strength) {
    case WEAK:
      printf("Your password is weak.\n");
      break;
    case FAIR:
      printf("Your password is fair.\n");
      break;
    case GOOD:
      printf("Your password is good.\n");
      break;
    case STRONG:
      printf("Your password is strong.\n");
      break;
  }
}

// Main function
int main() {
  // Get the password from the user
  char *password = get_password();

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength level
  print_password_strength(strength);

  // Free the memory allocated for the password
  free(password);

  return 0;
}