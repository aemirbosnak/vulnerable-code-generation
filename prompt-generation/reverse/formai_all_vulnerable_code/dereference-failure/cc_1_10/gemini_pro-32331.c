//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
// Linus Torvalds style C Password Strength Checker

// "Talk is cheap. Show me the code." - Linus Torvalds

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the password strength levels
#define WEAK "Weak"
#define MODERATE "Moderate"
#define STRONG "Strong"

// Check if the password contains at least one uppercase letter
int hasUppercase(char *password) {
  int i;
  for (i = 0; password[i] != '\0'; i++) {
    if (isupper(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one lowercase letter
int hasLowercase(char *password) {
  int i;
  for (i = 0; password[i] != '\0'; i++) {
    if (islower(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one digit
int hasDigit(char *password) {
  int i;
  for (i = 0; password[i] != '\0'; i++) {
    if (isdigit(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one special character
int hasSpecialCharacter(char *password) {
  int i;
  for (i = 0; password[i] != '\0'; i++) {
    if (!isalnum(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Check the strength of the password
char *checkPasswordStrength(char *password) {
  int score = 0;

  if (strlen(password) < 8) {
    return WEAK;
  }

  if (hasUppercase(password)) {
    score++;
  }

  if (hasLowercase(password)) {
    score++;
  }

  if (hasDigit(password)) {
    score++;
  }

  if (hasSpecialCharacter(password)) {
    score++;
  }

  switch (score) {
    case 1:
      return WEAK;
    case 2:
      return MODERATE;
    case 3:
    case 4:
      return STRONG;
    default:
      return WEAK;
  }
}

// Get the password from the user
char *getPassword() {
  char *password = (char *)malloc(100);
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Print the password strength
void printPasswordStrength(char *password, char *strength) {
  printf("Your password '%s' is %s.\n", password, strength);
}

// Main function
int main() {
  char *password = getPassword();
  char *strength = checkPasswordStrength(password);
  printPasswordStrength(password, strength);
  free(password);
  return 0;
}