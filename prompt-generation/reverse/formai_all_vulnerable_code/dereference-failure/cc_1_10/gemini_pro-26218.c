//GEMINI-pro DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 256

// Structure to store a password
typedef struct password {
  char *name;
  char *password;
  int length;
} password;

// Array of passwords
password passwords[MAX_PASSWORDS];

// Current number of passwords
int num_passwords = 0;

// Function to add a password to the array
void add_password(char *name, char *password) {
  // Check if there is room for another password
  if (num_passwords == MAX_PASSWORDS) {
    printf("Error: Password array is full.\n");
    return;
  }

  // Allocate memory for the new password
  passwords[num_passwords].name = malloc(strlen(name) + 1);
  passwords[num_passwords].password = malloc(strlen(password) + 1);

  // Copy the name and password into the new password
  strcpy(passwords[num_passwords].name, name);
  strcpy(passwords[num_passwords].password, password);

  // Set the length of the new password
  passwords[num_passwords].length = strlen(password);

  // Increment the number of passwords
  num_passwords++;
}

// Function to print all passwords
void print_passwords() {
  // Loop through all passwords
  for (int i = 0; i < num_passwords; i++) {
    // Print the name and password
    printf("%s: %s\n", passwords[i].name, passwords[i].password);
  }
}

// Function to generate a random password
char *generate_password(int length) {
  // Allocate memory for the new password
  char *password = malloc(length + 1);

  // Loop through all characters in the password
  for (int i = 0; i < length; i++) {
    // Generate a random character
    char character = rand() % 94 + 32;

    // If the character is not a printable character, generate a new one
    while (!isprint(character)) {
      character = rand() % 94 + 32;
    }

    // Add the character to the password
    password[i] = character;
  }

  // Null-terminate the password
  password[length] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Add some passwords to the array
  add_password("facebook", "mypassword123");
  add_password("gmail", "mypassword456");
  add_password("amazon", "mypassword789");

  // Print all passwords
  print_passwords();

  // Generate a random password
  char *password = generate_password(16);

  // Print the generated password
  printf("Generated password: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}