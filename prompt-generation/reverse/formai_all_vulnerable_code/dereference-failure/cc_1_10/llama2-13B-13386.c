//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: secure
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PASSWORD_LENGTH 12
#define MAX_LINE_LENGTH 1024

// Function to generate a secure password
void generate_password(char *password) {
  int i, j, k;
  for (i = 0; i < PASSWORD_LENGTH; i++) {
    // Generate a random character
    j = rand() % 97 + 32; // 32 is the ASCII code for space
    if (j > 122) {
      j = j - 26; // Convert uppercase to lowercase
    }
    password[i] = j;
  }
}

// Function to check if a given string is a password
int is_password(const char *str) {
  int i;
  for (i = 0; i < strlen(str); i++) {
    if (!isalnum(str[i])) {
      return 0; // Not a password
    }
  }
  return 1; // Password
}

int main() {
  char password[PASSWORD_LENGTH];
  generate_password(password);

  // Print the generated password
  printf("Generated password: %s\n", password);

  // Read input from the user
  char user_input[MAX_LINE_LENGTH];
  printf("Enter a password: ");
  fgets(user_input, MAX_LINE_LENGTH, stdin);

  // Check if the user's input is a password
  if (!is_password(user_input)) {
    printf("Invalid password. Please try again.\n");
    return 1;
  }

  // Compare the user's input with the generated password
  int compare = strcmp(password, user_input);
  if (compare == 0) {
    printf("Correct password! You may now access the secure system.\n");
  } else {
    printf("Incorrect password. Access denied.\n");
  }

  return 0;
}