//GEMINI-pro DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of passwords that can be stored
#define MAX_PASSWORDS 10

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the structure of a password entry
typedef struct {
  char *password;
  char *description;
} PasswordEntry;

// Define the array of password entries
PasswordEntry passwords[MAX_PASSWORDS];

// Define the current index of the password entry
int currentIndex = 0;

// Function to add a new password entry
void addPassword(char *password, char *description) {
  // Check if the array is full
  if (currentIndex == MAX_PASSWORDS) {
    printf("Error: The array of password entries is full.\n");
    return;
  }

  // Allocate memory for the password and description
  passwords[currentIndex].password = malloc(strlen(password) + 1);
  passwords[currentIndex].description = malloc(strlen(description) + 1);

  // Copy the password and description into the array
  strcpy(passwords[currentIndex].password, password);
  strcpy(passwords[currentIndex].description, description);

  // Increment the current index
  currentIndex++;
}

// Function to find a password entry by description
PasswordEntry *findPassword(char *description) {
  // Iterate over the array of password entries
  for (int i = 0; i < currentIndex; i++) {
    // Compare the description to the description of the current password entry
    if (strcmp(passwords[i].description, description) == 0) {
      // Return the current password entry
      return &passwords[i];
    }
  }

  // Return NULL if the password entry was not found
  return NULL;
}

// Function to delete a password entry by description
void deletePassword(char *description) {
  // Find the password entry by description
  PasswordEntry *passwordEntry = findPassword(description);

  // Check if the password entry was found
  if (passwordEntry == NULL) {
    printf("Error: The password entry was not found.\n");
    return;
  }

  // Free the memory for the password and description
  free(passwordEntry->password);
  free(passwordEntry->description);

  // Shift the remaining password entries down
  for (int i = currentIndex - 1; i >= 0; i--) {
    passwords[i] = passwords[i + 1];
  }

  // Decrement the current index
  currentIndex--;
}

// Function to print the array of password entries
void printPasswords() {
  // Iterate over the array of password entries
  for (int i = 0; i < currentIndex; i++) {
    // Print the password and description
    printf("%s: %s\n", passwords[i].description, passwords[i].password);
  }
}

// Main function
int main() {
  // Add some sample password entries
  addPassword("password1", "My first password");
  addPassword("password2", "My second password");
  addPassword("password3", "My third password");

  // Find a password entry by description
  PasswordEntry *passwordEntry = findPassword("password2");

  // Check if the password entry was found
  if (passwordEntry != NULL) {
    // Print the password
    printf("Password: %s\n", passwordEntry->password);
  } else {
    // Print an error message
    printf("Error: The password entry was not found.\n");
  }

  // Delete a password entry by description
  deletePassword("password3");

  // Print the array of password entries
  printPasswords();

  // Free the memory for the password entries
  for (int i = 0; i < currentIndex; i++) {
    free(passwords[i].password);
    free(passwords[i].description);
  }

  return 0;
}