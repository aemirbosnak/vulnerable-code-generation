//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 20

// Define the password character set
#define PASSWORD_CHAR_SET "!@#$%^&*()_-+"

// Define the password age threshold (in days)
#define PASSWORD_AGE_THRESHOLD 365

// Define the password strength threshold (1-100)
#define PASSWORD_STRENGTH_THRESHOLD 50

// Define the password cracking dictionary (for funny words)
#define PASSWORD_CRAWLING_DICTIONARY "dragonfirewhiskeyunicorn"

// Function to generate a random password
void generate_password(char *password) {
  int i, j;
  for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
    // Choose a random character from the password character set
    j = rand() % strlen(PASSWORD_CHAR_SET);
    password[i] = PASSWORD_CHAR_SET[j];
  }
}

// Function to check the password strength
int check_password_strength(char *password) {
  int score = 0;
  // Count the number of lowercase letters
  int lowercase_count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      lowercase_count++;
    }
  }
  // Count the number of uppercase letters
  int uppercase_count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      uppercase_count++;
    }
  }
  // Count the number of numbers
  int number_count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      number_count++;
    }
  }
  // Count the number of special characters
  int special_count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isalnum(password[i]) && password[i] != '0' && password[i] != '1') {
      special_count++;
    }
  }
  // Calculate the password strength score
  score = (lowercase_count + uppercase_count + number_count + special_count) * 2;
  return score;
}

// Function to check the password age
int check_password_age(char *password) {
  time_t now = time(NULL);
  time_t password_age = now - strtol(password, NULL, 10);
  return password_age / 365;
}

int main() {
  char password[MAX_PASSWORD_LENGTH];
  generate_password(password);
  printf("Your randomly generated password is: %s\n", password);
  int password_strength = check_password_strength(password);
  printf("Your password strength is: %d%%\n", password_strength);
  int password_age = check_password_age(password);
  printf("Your password age is: %d days\n", password_age);
  return 0;
}