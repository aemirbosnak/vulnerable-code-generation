//GEMINI-pro DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the maximum number of passwords to store
#define MAX_PASSWORDS 10

// Define the password structure
typedef struct password {
  char *name;
  char *value;
} password;

// Define the password manager structure
typedef struct password_manager {
  password passwords[MAX_PASSWORDS];
  int num_passwords;
} password_manager;

// Create a new password manager
password_manager *create_password_manager() {
  password_manager *manager = malloc(sizeof(password_manager));
  manager->num_passwords = 0;
  return manager;
}

// Free the memory allocated for a password manager
void free_password_manager(password_manager *manager) {
  for (int i = 0; i < manager->num_passwords; i++) {
    free(manager->passwords[i].name);
    free(manager->passwords[i].value);
  }
  free(manager);
}

// Add a new password to the password manager
void add_password(password_manager *manager, char *name, char *value) {
  if (manager->num_passwords >= MAX_PASSWORDS) {
    printf("Error: Password manager is full.\n");
    return;
  }

  manager->passwords[manager->num_passwords].name = strdup(name);
  manager->passwords[manager->num_passwords].value = strdup(value);
  manager->num_passwords++;
}

// Get the password value for a given name
char *get_password(password_manager *manager, char *name) {
  for (int i = 0; i < manager->num_passwords; i++) {
    if (strcmp(manager->passwords[i].name, name) == 0) {
      return manager->passwords[i].value;
    }
  }

  return NULL;
}

// Remove a password from the password manager
void remove_password(password_manager *manager, char *name) {
  for (int i = 0; i < manager->num_passwords; i++) {
    if (strcmp(manager->passwords[i].name, name) == 0) {
      free(manager->passwords[i].name);
      free(manager->passwords[i].value);
      manager->num_passwords--;
      for (int j = i; j < manager->num_passwords; j++) {
        manager->passwords[j] = manager->passwords[j + 1];
      }
      return;
    }
  }

  printf("Error: Password not found.\n");
}

// Print the contents of the password manager
void print_password_manager(password_manager *manager) {
  for (int i = 0; i < manager->num_passwords; i++) {
    printf("%s: %s\n", manager->passwords[i].name, manager->passwords[i].value);
  }
}

int main() {
  // Create a new password manager
  password_manager *manager = create_password_manager();

  // Add some passwords to the password manager
  add_password(manager, "email", "myemail@example.com");
  add_password(manager, "password", "mypassword123");
  add_password(manager, "bank account", "mybankaccount123456");

  // Get the password value for a given name
  char *password = get_password(manager, "email");
  printf("Email password: %s\n", password);

  // Remove a password from the password manager
  remove_password(manager, "password");

  // Print the contents of the password manager
  print_password_manager(manager);

  // Free the memory allocated for the password manager
  free_password_manager(manager);

  return 0;
}