//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct password_strength_checker {
  char *password;
  int strength;
  char **errors;
} password_strength_checker;

int calculate_password_strength(char *password) {
  int strength = 0;
  int has_upper_case = 0;
  int has_lower_case = 0;
  int has_numbers = 0;
  int has_symbols = 0;

  for (int i = 0; password[i] != '\0'; i++) {
    if (isupper(password[i])) {
      has_upper_case = 1;
    } else if (islower(password[i])) {
      has_lower_case = 1;
    } else if (isdigit(password[i])) {
      has_numbers = 1;
    } else if (ispunct(password[i])) {
      has_symbols = 1;
    }
  }

  if (has_upper_case && has_lower_case && has_numbers && has_symbols) {
    strength = 5;
  } else if (has_upper_case || has_lower_case || has_numbers || has_symbols) {
    strength = 3;
  } else {
    strength = 1;
  }

  return strength;
}

password_strength_checker *check_password_strength(char *password) {
  password_strength_checker *checker = malloc(sizeof(password_strength_checker));

  checker->password = strdup(password);
  checker->strength = calculate_password_strength(password);
  checker->errors = NULL;

  return checker;
}

int main() {
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter a password: ");
  fgets(password, MAX_PASSWORD_LENGTH, stdin);

  password_strength_checker *checker = check_password_strength(password);

  if (checker->strength == 5) {
    printf("Password is very strong.\n");
  } else if (checker->strength == 3) {
    printf("Password is strong.\n");
  } else {
    printf("Password is weak.\n");
  }

  free(checker);

  return 0;
}