//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
  char *password = malloc(100);

  printf("Enter your surrealist password: ");
  scanf("%s", password);

  int length = strlen(password);

  // The password must be at least 8 characters long
  if (length < 8) {
    printf("Your password is too short. It must be at least 8 characters long.\n");
    return 1;
  }

  // The password must contain at least one uppercase letter
  int hasUppercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = 1;
      break;
    }
  }

  if (!hasUppercase) {
    printf("Your password must contain at least one uppercase letter.\n");
    return 1;
  }

  // The password must contain at least one lowercase letter
  int hasLowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = 1;
      break;
    }
  }

  if (!hasLowercase) {
    printf("Your password must contain at least one lowercase letter.\n");
    return 1;
  }

  // The password must contain at least one digit
  int hasDigit = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasDigit = 1;
      break;
    }
  }

  if (!hasDigit) {
    printf("Your password must contain at least one digit.\n");
    return 1;
  }

  // The password must contain at least one special character
  int hasSpecial = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '!' && password[i] <= '~') {
      hasSpecial = 1;
      break;
    }
  }

  if (!hasSpecial) {
    printf("Your password must contain at least one special character.\n");
    return 1;
  }

  // The password must not contain any spaces
  for (int i = 0; i < length; i++) {
    if (password[i] == ' ') {
      printf("Your password must not contain any spaces.\n");
      return 1;
    }
  }

  // The password must not be too common
  char *commonPasswords[] = {"password", "123456", "12345678", "123456789", "1234567890", "qwerty", "1qaz2wsx", "abc123", "iloveyou", "princess"};
  int numCommonPasswords = sizeof(commonPasswords) / sizeof(char *);
  for (int i = 0; i < numCommonPasswords; i++) {
    if (strcmp(password, commonPasswords[i]) == 0) {
      printf("Your password is too common. Please choose a more unique password.\n");
      return 1;
    }
  }

  // The password is strong enough
  printf("Your password is strong enough. Thank you for using our surrealist password checker.\n");
  return 0;
}