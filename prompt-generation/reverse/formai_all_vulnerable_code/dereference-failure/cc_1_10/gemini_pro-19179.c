//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char generate_random_character() {
  int random_number = rand() % 94 + 32;
  return (char)random_number;
}

// Function to generate a random string of a given length
char *generate_random_string(int length) {
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    password[i] = generate_random_character();
  }
  password[length] = '\0';
  return password;
}

// Function to check if a given string contains any uppercase letters
int contains_uppercase(char *string) {
  int length = strlen(string);
  for (int i = 0; i < length; i++) {
    if (string[i] >= 'A' && string[i] <= 'Z') {
      return 1;
    }
  }
  return 0;
}

// Function to check if a given string contains any lowercase letters
int contains_lowercase(char *string) {
  int length = strlen(string);
  for (int i = 0; i < length; i++) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      return 1;
    }
  }
  return 0;
}

// Function to check if a given string contains any digits
int contains_digits(char *string) {
  int length = strlen(string);
  for (int i = 0; i < length; i++) {
    if (string[i] >= '0' && string[i] <= '9') {
      return 1;
    }
  }
  return 0;
}

// Function to check if a given string contains any special characters
int contains_special_characters(char *string) {
  int length = strlen(string);
  for (int i = 0; i < length; i++) {
    if (string[i] < 'a' || string[i] > 'z') {
      return 1;
    }
  }
  return 0;
}

// Function to generate a secure password of a given length
char *generate_secure_password(int length) {
  srand(time(NULL));
  char *password = generate_random_string(length);
  while (!contains_uppercase(password) || !contains_lowercase(password) || !contains_digits(password) || !contains_special_characters(password)) {
    free(password);
    password = generate_random_string(length);
  }
  return password;
}

// Main function
int main() {
  int length = 10;
  char *password = generate_secure_password(length);
  printf("Generated password: %s\n", password);
  free(password);
  return 0;
}