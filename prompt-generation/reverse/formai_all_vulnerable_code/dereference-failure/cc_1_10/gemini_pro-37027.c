//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to check if a character is a vowel
int isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Function to check if a character is a consonant
int isConsonant(char c) {
  return (!isVowel(c) && (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a character is a digit
int isDigit(char c) { return (c >= '0' && c <= '9'); }

// Function to check if a character is a special character
int isSpecialCharacter(char c) {
  return (!isVowel(c) && !isConsonant(c) && !isDigit(c));
}

// Function to calculate the strength of a password
int calculatePasswordStrength(char *password) {
  int strength = 0;
  int length = strlen(password);

  // Check for the length of the password
  if (length < 8) {
    strength += 1;
  } else if (length >= 8 && length <= 10) {
    strength += 2;
  } else if (length > 10) {
    strength += 3;
  }

  // Check for the presence of vowels
  int vowelCount = 0;
  for (int i = 0; i < length; i++) {
    if (isVowel(password[i])) {
      vowelCount++;
    }
  }
  if (vowelCount == 0) {
    strength += 1;
  } else if (vowelCount == 1 || vowelCount == 2) {
    strength += 2;
  } else if (vowelCount >= 3) {
    strength += 3;
  }

  // Check for the presence of consonants
  int consonantCount = 0;
  for (int i = 0; i < length; i++) {
    if (isConsonant(password[i])) {
      consonantCount++;
    }
  }
  if (consonantCount == 0) {
    strength += 1;
  } else if (consonantCount == 1 || consonantCount == 2) {
    strength += 2;
  } else if (consonantCount >= 3) {
    strength += 3;
  }

  // Check for the presence of digits
  int digitCount = 0;
  for (int i = 0; i < length; i++) {
    if (isDigit(password[i])) {
      digitCount++;
    }
  }
  if (digitCount == 0) {
    strength += 1;
  } else if (digitCount == 1 || digitCount == 2) {
    strength += 2;
  } else if (digitCount >= 3) {
    strength += 3;
  }

  // Check for the presence of special characters
  int specialCharacterCount = 0;
  for (int i = 0; i < length; i++) {
    if (isSpecialCharacter(password[i])) {
      specialCharacterCount++;
    }
  }
  if (specialCharacterCount == 0) {
    strength += 1;
  } else if (specialCharacterCount == 1 || specialCharacterCount == 2) {
    strength += 2;
  } else if (specialCharacterCount >= 3) {
    strength += 3;
  }

  return strength;
}

// Function to generate a random password
char *generateRandomPassword(int length) {
  char *password = malloc(length + 1);
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    int random = rand() % 4;
    if (random == 0) {
      password[i] = 'a' + rand() % 26;
    } else if (random == 1) {
      password[i] = 'A' + rand() % 26;
    } else if (random == 2) {
      password[i] = '0' + rand() % 10;
    } else if (random == 3) {
      password[i] = '!' + rand() % 15;
    }
  }
  password[length] = '\0';
  return password;
}

int main() {
  // Get the input password from the user
  char password[100];
  printf("Enter your password: ");
  gets(password);

  // Calculate the strength of the password
  int strength = calculatePasswordStrength(password);

  // Print the strength of the password
  printf("The strength of your password is: %d\n", strength);

  // Generate a random password
  int length = 10;
  char *randomPassword = generateRandomPassword(length);

  // Print the random password
  printf("Here is a random password of length %d: %s\n", length, randomPassword);

  return 0;
}