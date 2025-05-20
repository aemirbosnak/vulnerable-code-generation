//GEMINI-pro DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

// Structure to store a password
typedef struct {
  char *name;
  char *password;
} Password;

// Array of passwords
Password passwords[MAX_PASSWORDS];

// Index of the current password
int current_password = -1;

// Function to add a new password
void add_password(char *name, char *password) {
  // Check if the array is full
  if (current_password >= MAX_PASSWORDS - 1) {
    printf("Error: Password array is full.\n");
    return;
  }

  // Increment the current password index
  current_password++;

  // Allocate memory for the name and password
  passwords[current_password].name = malloc(strlen(name) + 1);
  passwords[current_password].password = malloc(strlen(password) + 1);

  // Copy the name and password into the array
  strcpy(passwords[current_password].name, name);
  strcpy(passwords[current_password].password, password);
}

// Function to get a password
char *get_password(char *name) {
  // Loop through the array of passwords
  for (int i = 0; i <= current_password; i++) {
    // Check if the name matches
    if (strcmp(passwords[i].name, name) == 0) {
      // Return the password
      return passwords[i].password;
    }
  }

  // Return NULL if the password was not found
  return NULL;
}

// Function to delete a password
void delete_password(char *name) {
  // Loop through the array of passwords
  for (int i = 0; i <= current_password; i++) {
    // Check if the name matches
    if (strcmp(passwords[i].name, name) == 0) {
      // Free the memory allocated for the name and password
      free(passwords[i].name);
      free(passwords[i].password);

      // Shift the remaining passwords down one index
      for (int j = i; j < current_password; j++) {
        passwords[j] = passwords[j + 1];
      }

      // Decrement the current password index
      current_password--;

      // Return
      return;
    }
  }

  // Print an error message if the password was not found
  printf("Error: Password not found.\n");
}

// Function to print all passwords
void print_passwords() {
  // Loop through the array of passwords
  for (int i = 0; i <= current_password; i++) {
    // Print the name and password
    printf("%s: %s\n", passwords[i].name, passwords[i].password);
  }
}

// Main function
int main() {
  // Add some passwords to the array
  add_password("Google", "password1");
  add_password("Facebook", "password2");
  add_password("Twitter", "password3");

  // Get a password from the array
  char *password = get_password("Google");

  // Print the password
  printf("Password for Google: %s\n", password);

  // Delete a password from the array
  delete_password("Twitter");

  // Print all passwords
  print_passwords();

  return 0;
}