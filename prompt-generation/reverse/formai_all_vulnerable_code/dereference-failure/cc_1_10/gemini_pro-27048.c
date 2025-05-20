//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int checkPasswordStrength(char* password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  }

  // Check if the password contains at least one uppercase letter
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength += 1;
      break;
    }
  }

  // Check if the password contains at least one lowercase letter
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength += 1;
      break;
    }
  }

  // Check if the password contains at least one digit
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength += 1;
      break;
    }
  }

  // Check if the password contains at least one special character
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength += 1;
      break;
    }
  }

  // Return the strength of the password
  return strength;
}

// Function to get the password from the user
char* getPassword() {
  char* password = (char*)malloc(100 * sizeof(char));

  printf("Enter your password: ");
  scanf("%s", password);

  return password;
}

// Main function
int main() {
  // Get the password from the user
  char* password = getPassword();

  // Check the strength of the password
  int strength = checkPasswordStrength(password);

  // Print the strength of the password
  printf("The strength of your password is: %d\n", strength);

  // Free the memory allocated for the password
  free(password);

  return 0;
}