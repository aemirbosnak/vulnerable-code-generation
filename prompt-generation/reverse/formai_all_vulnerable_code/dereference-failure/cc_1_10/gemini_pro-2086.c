//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 32

// Define the character types
#define TYPE_UPPERCASE 0
#define TYPE_LOWERCASE 1
#define TYPE_DIGIT 2
#define TYPE_SPECIAL 3

// Define the character type weights
#define WEIGHT_UPPERCASE 3
#define WEIGHT_LOWERCASE 2
#define WEIGHT_DIGIT 1
#define WEIGHT_SPECIAL 4

// Define the character type scores
#define SCORE_UPPERCASE 10
#define SCORE_LOWERCASE 5
#define SCORE_DIGIT 1
#define SCORE_SPECIAL 15

// Define the password strength score thresholds
#define THRESHOLD_WEAK 20
#define THRESHOLD_MEDIUM 40
#define THRESHOLD_STRONG 60

// Define the password strength messages
#define MESSAGE_WEAK "Your password is weak."
#define MESSAGE_MEDIUM "Your password is medium."
#define MESSAGE_STRONG "Your password is strong."

// Get the password from the user
char *get_password() {
  char *password = (char *)malloc(MAX_PASSWORD_LENGTH + 1);
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Calculate the password strength
int calculate_password_strength(char *password) {
  int length = strlen(password);

  // Check the password length
  if (length < MIN_PASSWORD_LENGTH) {
    return STRENGTH_WEAK;
  }

  // Calculate the character type counts
  int counts[TYPE_SPECIAL + 1] = {0};
  for (int i = 0; i < length; i++) {
    char c = password[i];
    if (c >= 'A' && c <= 'Z') {
      counts[TYPE_UPPERCASE]++;
    } else if (c >= 'a' && c <= 'z') {
      counts[TYPE_LOWERCASE]++;
    } else if (c >= '0' && c <= '9') {
      counts[TYPE_DIGIT]++;
    } else {
      counts[TYPE_SPECIAL]++;
    }
  }

  // Calculate the character type weights
  int weights[TYPE_SPECIAL + 1] = {0};
  weights[TYPE_UPPERCASE] = WEIGHT_UPPERCASE;
  weights[TYPE_LOWERCASE] = WEIGHT_LOWERCASE;
  weights[TYPE_DIGIT] = WEIGHT_DIGIT;
  weights[TYPE_SPECIAL] = WEIGHT_SPECIAL;

  // Calculate the character type scores
  int scores[TYPE_SPECIAL + 1] = {0};
  scores[TYPE_UPPERCASE] = SCORE_UPPERCASE;
  scores[TYPE_LOWERCASE] = SCORE_LOWERCASE;
  scores[TYPE_DIGIT] = SCORE_DIGIT;
  scores[TYPE_SPECIAL] = SCORE_SPECIAL;

  // Calculate the password strength score
  int score = 0;
  for (int i = 0; i < TYPE_SPECIAL + 1; i++) {
    score += counts[i] * weights[i] * scores[i];
  }

  // Determine the password strength level
  if (score < THRESHOLD_WEAK) {
    return STRENGTH_WEAK;
  } else if (score < THRESHOLD_MEDIUM) {
    return STRENGTH_MEDIUM;
  } else {
    return STRENGTH_STRONG;
  }
}

// Print the password strength message
void print_password_strength(int strength) {
  switch (strength) {
  case STRENGTH_WEAK:
    printf("%s\n", MESSAGE_WEAK);
    break;
  case STRENGTH_MEDIUM:
    printf("%s\n", MESSAGE_MEDIUM);
    break;
  case STRENGTH_STRONG:
    printf("%s\n", MESSAGE_STRONG);
    break;
  }
}

// Main function
int main() {
  // Get the password from the user
  char *password = get_password();

  // Calculate the password strength
  int strength = calculate_password_strength(password);

  // Print the password strength message
  print_password_strength(strength);

  // Free the allocated memory
  free(password);

  return 0;
}