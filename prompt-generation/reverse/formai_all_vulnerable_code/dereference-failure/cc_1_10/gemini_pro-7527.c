//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Define the password strength criteria
#define MIN_LENGTH 8
#define HAS_UPPERCASE 1
#define HAS_LOWERCASE 1
#define HAS_DIGIT 1
#define HAS_SPECIAL_CHAR 1

// Define the password strength levels
#define WEAK 0
#define FAIR 1
#define GOOD 2
#define STRONG 3

// Check if the password meets the minimum length requirement
int check_length(char *password) {
  return strlen(password) >= MIN_LENGTH;
}

// Check if the password contains at least one uppercase letter
int check_uppercase(char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one lowercase letter
int check_lowercase(char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one digit
int check_digit(char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one special character
int check_special_char(char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (!((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9'))) {
      return 1;
    }
  }
  return 0;
}

// Calculate the password strength
int calculate_strength(char *password) {
  int strength = 0;
  if (check_length(password)) {
    strength += 1;
  }
  if (check_uppercase(password)) {
    strength += 1;
  }
  if (check_lowercase(password)) {
    strength += 1;
  }
  if (check_digit(password)) {
    strength += 1;
  }
  if (check_special_char(password)) {
    strength += 1;
  }
  return strength;
}

// Print the password strength
void print_strength(int strength) {
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
    default:
      printf("Invalid password strength.\n");
  }
}

// Get the password from the user
char *get_password() {
  char *password = (char *)malloc(100 * sizeof(char));
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Main function
int main() {
  char *password = get_password();
  int strength = calculate_strength(password);
  print_strength(strength);
  return 0;
}