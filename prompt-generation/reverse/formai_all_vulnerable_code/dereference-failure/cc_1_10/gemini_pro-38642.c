//GEMINI-pro DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password vault
typedef struct {
  char *name;
  char *password;
} Password;

// Password vault array
Password *passwords;

// Number of passwords in the vault
int num_passwords = 0;

// Initialize the password vault
void init_vault() {
  // Allocate memory for the vault
  passwords = malloc(sizeof(Password) * 10);  // Initial size of 10 passwords

  // Set the initial number of passwords to 0
  num_passwords = 0;
}

// Add a password to the vault
void add_password(char *name, char *password) {
  // Check if the vault is full
  if (num_passwords >= 10) {
    // Reallocate memory for the vault
    passwords = realloc(passwords, sizeof(Password) * (num_passwords + 1));
  }

  // Add the password to the vault
  passwords[num_passwords].name = malloc(strlen(name) + 1);
  strcpy(passwords[num_passwords].name, name);
  passwords[num_passwords].password = malloc(strlen(password) + 1);
  strcpy(passwords[num_passwords].password, password);

  // Increment the number of passwords in the vault
  num_passwords++;
}

// Get a password from the vault
char *get_password(char *name) {
  // Iterate over the passwords in the vault
  for (int i = 0; i < num_passwords; i++) {
    // Check if the name matches
    if (strcmp(passwords[i].name, name) == 0) {
      // Return the password
      return passwords[i].password;
    }
  }

  // Password not found
  return NULL;
}

// Delete a password from the vault
void delete_password(char *name) {
  // Iterate over the passwords in the vault
  for (int i = 0; i < num_passwords; i++) {
    // Check if the name matches
    if (strcmp(passwords[i].name, name) == 0) {
      // Free the memory for the password
      free(passwords[i].name);
      free(passwords[i].password);

      // Shift the remaining passwords down
      for (int j = i; j < num_passwords - 1; j++) {
        passwords[j] = passwords[j + 1];
      }

      // Decrement the number of passwords in the vault
      num_passwords--;

      // Break out of the loop
      break;
    }
  }
}

// Print the passwords in the vault
void print_passwords() {
  // Iterate over the passwords in the vault
  for (int i = 0; i < num_passwords; i++) {
    // Print the password name and password
    printf("%s: %s\n", passwords[i].name, passwords[i].password);
  }
}

// Main function
int main() {
  // Initialize the password vault
  init_vault();

  // Add some passwords to the vault
  add_password("Facebook", "my_facebook_password");
  add_password("Google", "my_google_password");
  add_password("Amazon", "my_amazon_password");

  // Get a password from the vault
  char *password = get_password("Google");
  printf("Google password: %s\n", password);

  // Delete a password from the vault
  delete_password("Amazon");

  // Print the passwords in the vault
  print_passwords();

  return 0;
}