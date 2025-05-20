//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Macros to generate random numbers
#define RAND_CHAR(min, max) (min + rand() % (max - min + 1))
#define RAND_BOOL() (rand() % 2 == 0)

// Types of characters used in the password
typedef enum {
  ALPHA_LOWER,
  ALPHA_UPPER,
  NUMERIC,
  SYMBOL,
  WHITESPACE
} char_type;

// Function to generate random number
unsigned int rand_int(unsigned int min, unsigned int max) {
  return min + (rand() % (max - min + 1));
}

// Function to generate a random character
char rand_char(void) {
  switch (rand_int(0, 4)) {
    case ALPHA_LOWER:
      return 'a' + rand_char();
    case ALPHA_UPPER:
      return 'A' + rand_char();
    case NUMERIC:
      return '0' + rand_char();
    case SYMBOL:
      return "!@#$%^&*();:?"[rand_char()];
    default:
      return ' ' + rand_char();
  }
}

// Function to generate a random password
char *rand_password(unsigned int len) {
  char *password = malloc(len + 1);
  for (unsigned int i = 0; i < len; i++) {
    password[i] = rand_char();
  }
  password[len] = '\0';
  return password;
}

int main(void) {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random password of length 16
  char *password = rand_password(16);

  // Print the generated password
  printf("Your randomly generated password is: %s\n", password);

  // Free the allocated memory
  free(password);

  return 0;
}