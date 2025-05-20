//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 256

// A password entry
typedef struct {
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

// The password manager
typedef struct {
  PasswordEntry passwords[MAX_PASSWORDS];
  int num_passwords;
} PasswordManager;

// Create a new password manager
PasswordManager *new_password_manager() {
  PasswordManager *pm = malloc(sizeof(PasswordManager));
  pm->num_passwords = 0;
  return pm;
}

// Add a new password entry to the manager
void add_password_entry(PasswordManager *pm, PasswordEntry *entry) {
  if (pm->num_passwords < MAX_PASSWORDS) {
    pm->passwords[pm->num_passwords] = *entry;
    pm->num_passwords++;
  }
}

// Find a password entry by username
PasswordEntry *find_password_entry(PasswordManager *pm, char *username) {
  for (int i = 0; i < pm->num_passwords; i++) {
    if (strcmp(pm->passwords[i].username, username) == 0) {
      return &pm->passwords[i];
    }
  }
  return NULL;
}

// Print all the password entries
void print_password_entries(PasswordManager *pm) {
  for (int i = 0; i < pm->num_passwords; i++) {
    printf("%s: %s\n", pm->passwords[i].username, pm->passwords[i].password);
  }
}

// Free the memory allocated for the password manager
void free_password_manager(PasswordManager *pm) {
  free(pm);
}

int main() {
  PasswordManager *pm = new_password_manager();

  // Add some password entries
  PasswordEntry entry1 = {"username1", "password1"};
  add_password_entry(pm, &entry1);
  PasswordEntry entry2 = {"username2", "password2"};
  add_password_entry(pm, &entry2);
  PasswordEntry entry3 = {"username3", "password3"};
  add_password_entry(pm, &entry3);

  // Find a password entry by username
  PasswordEntry *entry = find_password_entry(pm, "username2");
  if (entry != NULL) {
    printf("Found password entry: %s: %s\n", entry->username, entry->password);
  } else {
    printf("Password entry not found.\n");
  }

  // Print all the password entries
  print_password_entries(pm);

  // Free the memory allocated for the password manager
  free_password_manager(pm);

  return 0;
}