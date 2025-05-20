//GEMINI-pro DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

// Structure to store a password
typedef struct {
  char *name;
  char *password;
} Password;

// Function to create a new password
Password *new_password(char *name, char *password) {
  Password *new_password = malloc(sizeof(Password));
  new_password->name = strdup(name);
  new_password->password = strdup(password);
  return new_password;
}

// Function to compare two passwords
int compare_passwords(Password *password1, Password *password2) {
  return strcmp(password1->password, password2->password) == 0;
}

// Function to print a password
void print_password(Password *password) {
  printf("Name: %s\n", password->name);
  printf("Password: %s\n", password->password);
}

// Function to free a password
void free_password(Password *password) {
  free(password->name);
  free(password->password);
  free(password);
}

// Main function
int main() {
  // Create an array of passwords
  Password *passwords[MAX_PASSWORDS];

  // Add some passwords to the array
  passwords[0] = new_password("John Doe", "password1");
  passwords[1] = new_password("Jane Doe", "password2");
  passwords[2] = new_password("Jack Doe", "password3");

  // Print the passwords
  for (int i = 0; i < 3; i++) {
    print_password(passwords[i]);
  }

  // Free the passwords
  for (int i = 0; i < 3; i++) {
    free_password(passwords[i]);
  }

  return 0;
}