//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 12

int main(void) {
  printf("Welcome to the Password Management System!\n");
  printf("Please enter your username: ");
  char username[20];
  scanf("%s", username);
  printf("Welcome, %s!\n", username);

  char *password = malloc((PASSWORD_LENGTH + 1) * sizeof(char));
  memset(password, 0, PASSWORD_LENGTH + 1);

  int num_attempts = 0;
  while (num_attempts < 3) {
    printf("Please enter your password: ");
    scanf("%s", password);
    if (strcmp(password, "password123") == 0) {
      printf("Access granted! You're in the system!\n");
      break;
    } else {
      printf("Access denied! That is the wrong password!\n");
      num_attempts++;
    }
  }

  if (num_attempts == 3) {
    printf("You have reached the maximum number of attempts. Please try again later.\n");
  }

  // Now, let's generate a new password for the user
  char *new_password = malloc((PASSWORD_LENGTH + 1) * sizeof(char));
  memset(new_password, 0, PASSWORD_LENGTH + 1);
  printf("Generating your new password...\n");

  // First, let's create a string of all possible characters for the password
  char *all_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=";
  int num_chars = strlen(all_chars);

  // Now, let's randomly select characters from all_chars to create the new password
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    int random_index = rand() % num_chars;
    new_password[i] = all_chars[random_index];
  }

  // Print the new password to the user and store it securely!
  printf("Your new password is: %s\n", new_password);

  // Free the allocated memory
  free(password);
  free(new_password);

  printf("Thank you for using the Password Management System! Exiting now...\n");
  return 0;
}