//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character set for password generation
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"

// Define the maximum password length
#define MAX_PASS_LEN 20

// Function to generate a random password
char *generate_password(int len) {
  // Allocate memory for the password
  char *password = malloc(len + 1);
  if (password == NULL) {
    return NULL;
  }

  // Initialize the random number generator
  srand(time(NULL));

  // Generate the password
  for (int i = 0; i < len; i++) {
    password[i] = CHARSET[rand() % strlen(CHARSET)];
  }

  // Null-terminate the password
  password[len] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Get the desired password length from the user
  int len;
  printf("Enter the desired password length (max %d): ", MAX_PASS_LEN);
  scanf("%d", &len);

  // Generate a random password
  char *password = generate_password(len);

  // Print the password
  printf("Generated password: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}