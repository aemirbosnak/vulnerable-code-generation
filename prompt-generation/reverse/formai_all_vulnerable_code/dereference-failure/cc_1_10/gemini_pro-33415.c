//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Define the character sets
char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char number_chars[] = "0123456789";
char special_chars[] = "!@#$%^&*()_+=-";

// Define the password length
#define PASSWORD_LENGTH 16

// Function to generate a random character from a character set
char generate_random_char(char *char_set) {
  int index = rand() % strlen(char_set);
  return char_set[index];
}

// Function to generate a secure password
char *generate_secure_password() {
  // Initialize the password
  char *password = malloc(sizeof(char) * PASSWORD_LENGTH);

  // Generate a random character from each character set
  password[0] = generate_random_char(lowercase_chars);
  password[1] = generate_random_char(uppercase_chars);
  password[2] = generate_random_char(number_chars);
  password[3] = generate_random_char(special_chars);

  // Generate the remaining characters randomly
  for (int i = 4; i < PASSWORD_LENGTH; i++) {
    int char_set_index = rand() % 4;
    switch (char_set_index) {
      case 0:
        password[i] = generate_random_char(lowercase_chars);
        break;
      case 1:
        password[i] = generate_random_char(uppercase_chars);
        break;
      case 2:
        password[i] = generate_random_char(number_chars);
        break;
      case 3:
        password[i] = generate_random_char(special_chars);
        break;
    }
  }

  // Return the password
  return password;
}

// Function to test the password generator
void test_password_generator() {
  // Generate 10 passwords
  for (int i = 0; i < 10; i++) {
    char *password = generate_secure_password();
    printf("%s\n", password);
    free(password);
  }
}

int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Test the password generator
  test_password_generator();

  return 0;
}