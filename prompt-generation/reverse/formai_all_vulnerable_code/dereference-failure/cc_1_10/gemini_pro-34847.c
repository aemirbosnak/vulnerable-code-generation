//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  } else if (strlen(password) < 12) {
    strength += 2;
  } else {
    strength += 3;
  }

  // Check for uppercase characters
  int has_uppercase = 0;
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  if (has_uppercase) {
    strength += 1;
  }

  // Check for lowercase characters
  int has_lowercase = 0;
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  if (has_lowercase) {
    strength += 1;
  }

  // Check for numbers
  int has_number = 0;
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_number = 1;
      break;
    }
  }
  if (has_number) {
    strength += 1;
  }

  // Check for special characters
  int has_special_character = 0;
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      has_special_character = 1;
      break;
    }
  }
  if (has_special_character) {
    strength += 1;
  }

  return strength;
}

// Function to generate a random password
char *generate_random_password(int length) {
  char *password = malloc(length + 1);

  for (int i = 0; i < length; i++) {
    int random_number = rand() % 94 + 33;
    char random_character = (char)random_number;
    password[i] = random_character;
  }

  password[length] = '\0';

  return password;
}

int main() {
  // Get the desired password length from the user
  int length;
  printf("Enter the desired password length: ");
  scanf("%d", &length);

  // Generate a random password
  char *password = generate_random_password(length);

  // Check the strength of the password
  int strength = check_password_strength(password);

  // Print the password and its strength
  printf("Password: %s\n", password);
  printf("Password strength: %d\n", strength);

  return 0;
}