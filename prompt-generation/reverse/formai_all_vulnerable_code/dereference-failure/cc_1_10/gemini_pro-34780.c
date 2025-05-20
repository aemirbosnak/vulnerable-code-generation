//GEMINI-pro DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the data structure for a password entry.
typedef struct {
  char *name;
  char *password;
} password_entry;

// Declare the array of password entries.
password_entry passwords[100];

// Declare the number of password entries.
int num_passwords = 0;

// Function to add a new password entry.
void add_password_entry(char *name, char *password) {
  // Check if the number of password entries has reached the maximum.
  if (num_passwords >= 100) {
    printf("Error: Maximum number of password entries reached.\n");
    return;
  }

  // Allocate memory for the new password entry.
  passwords[num_passwords].name = malloc(strlen(name) + 1);
  passwords[num_passwords].password = malloc(strlen(password) + 1);

  // Copy the name and password into the new password entry.
  strcpy(passwords[num_passwords].name, name);
  strcpy(passwords[num_passwords].password, password);

  // Increment the number of password entries.
  num_passwords++;
}

// Function to find a password entry by name.
password_entry *find_password_entry(char *name) {
  // Loop through the array of password entries.
  for (int i = 0; i < num_passwords; i++) {
    // If the name of the password entry matches the given name, return the password entry.
    if (strcmp(passwords[i].name, name) == 0) {
      return &passwords[i];
    }
  }

  // If the password entry was not found, return NULL.
  return NULL;
}

// Function to print all password entries.
void print_password_entries() {
  // Loop through the array of password entries.
  for (int i = 0; i < num_passwords; i++) {
    // Print the name and password of the password entry.
    printf("%s: %s\n", passwords[i].name, passwords[i].password);
  }
}

// Main function.
int main() {
  // Add some sample password entries.
  add_password_entry("Alice", "password1");
  add_password_entry("Bob", "password2");
  add_password_entry("Carol", "password3");

  // Find a password entry by name.
  password_entry *password_entry = find_password_entry("Bob");

  // If the password entry was found, print the name and password.
  if (password_entry != NULL) {
    printf("Name: %s\n", password_entry->name);
    printf("Password: %s\n", password_entry->password);
  } else {
    printf("Error: Password entry not found.\n");
  }

  // Print all password entries.
  printf("\nAll password entries:\n");
  print_password_entries();

  return 0;
}