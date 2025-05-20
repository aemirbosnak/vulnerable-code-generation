//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

/**
 * Generates a random digit or special character
**/
char getRandomChar() {
  char specialChars[] = {'!', '@', '#', '$', '%', '&', '*'};
  bool generateChar = rand() % 2 == 0;

  if (generateChar) {
    return specialChars[rand() % 7];
  } else {
    return (char) (rand() % 10 + 48);
  }
}

/**
 * Creates a secure password with a random length between 8 and 16
**/
char* createSecurePassword() {
  int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
  char* password = (char*) malloc((length + 1) * sizeof(char));

  for (int i = 0; i < length; i++) {
    password[i] = getRandomChar();
  }

  password[length] = '\0';

  return password;
}

int main() {
  srand(time(NULL));
  int numPasswords = 5;
  char** passwords = (char**) malloc(numPasswords * sizeof(char*));

  printf("Generating %d secure passwords:\n\n", numPasswords);

  for (int i = 0; i < numPasswords; i++) {
    passwords[i] = createSecurePassword();
    printf("Password %d: %s\n", i + 1, passwords[i]);
  }

  // Free allocated memory
  for (int i = 0; i < numPasswords; i++) {
    free(passwords[i]);
  }

  free(passwords);

  return 0;
}