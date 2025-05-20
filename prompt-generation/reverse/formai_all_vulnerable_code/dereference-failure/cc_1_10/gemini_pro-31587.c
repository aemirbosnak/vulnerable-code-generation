//GEMINI-pro DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100

// Data structure to store a password
typedef struct {
  char username[MAX_PASSWORD_LEN];
  char password[MAX_PASSWORD_LEN];
} Password;

// Data structure to store all passwords
typedef struct {
  Password passwords[MAX_PASSWORDS];
  int num_passwords;
} PasswordManager;

// Function to create a new password manager
PasswordManager* create_password_manager() {
  PasswordManager* manager = malloc(sizeof(PasswordManager));
  manager->num_passwords = 0;
  return manager;
}

// Function to add a new password to the manager
void add_password(PasswordManager* manager, char* username, char* password) {
  if (manager->num_passwords >= MAX_PASSWORDS) {
    printf("Error: Password manager is full.\n");
    return;
  }

  strcpy(manager->passwords[manager->num_passwords].username, username);
  strcpy(manager->passwords[manager->num_passwords].password, password);
  manager->num_passwords++;
}

// Function to search for a password in the manager
char* find_password(PasswordManager* manager, char* username) {
  for (int i = 0; i < manager->num_passwords; i++) {
    if (strcmp(manager->passwords[i].username, username) == 0) {
      return manager->passwords[i].password;
    }
  }

  return NULL;
}

// Function to delete a password from the manager
void delete_password(PasswordManager* manager, char* username) {
  for (int i = 0; i < manager->num_passwords; i++) {
    if (strcmp(manager->passwords[i].username, username) == 0) {
      for (int j = i + 1; j < manager->num_passwords; j++) {
        manager->passwords[j - 1] = manager->passwords[j];
      }
      manager->num_passwords--;
      return;
    }
  }

  printf("Error: Password not found.\n");
}

// Function to print all passwords in the manager
void print_passwords(PasswordManager* manager) {
  for (int i = 0; i < manager->num_passwords; i++) {
    printf("%s: %s\n", manager->passwords[i].username, manager->passwords[i].password);
  }
}

// Main function
int main() {
  // Create a new password manager
  PasswordManager* manager = create_password_manager();

  // Add some passwords to the manager
  add_password(manager, "username1", "password1");
  add_password(manager, "username2", "password2");
  add_password(manager, "username3", "password3");

  // Search for a password in the manager
  char* password = find_password(manager, "username2");
  if (password != NULL) {
    printf("Found password for username2: %s\n", password);
  } else {
    printf("Password not found for username2.\n");
  }

  // Delete a password from the manager
  delete_password(manager, "username1");

  // Print all passwords in the manager
  printf("All passwords:\n");
  print_passwords(manager);

  // Free the memory used by the password manager
  free(manager);

  return 0;
}