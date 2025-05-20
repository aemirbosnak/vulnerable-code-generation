//GEMINI-pro DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A vault to keep our precious passwords
typedef struct PasswordVault {
  char *name;
  char *password;
  struct PasswordVault *next;
} PasswordVault;

// The guardian of the vault, the keeper of secrets
PasswordVault *keeper = NULL;

// A helper function to create a new entry in the vault
PasswordVault *createVaultEntry(char *name, char *password) {
  PasswordVault *newEntry = (PasswordVault *)malloc(sizeof(PasswordVault));
  newEntry->name = strdup(name);
  newEntry->password = strdup(password);
  newEntry->next = NULL;
  return newEntry;
}

// A function to add an entry to the vault
void addToVault(char *name, char *password) {
  if (keeper == NULL) {
    keeper = createVaultEntry(name, password);
  } else {
    PasswordVault *current = keeper;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = createVaultEntry(name, password);
  }
}

// A function to retrieve a password from the vault
char *getPassword(char *name) {
  PasswordVault *current = keeper;
  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      return current->password;
    }
    current = current->next;
  }
  return NULL;
}

// A function to display all the entries in the vault
void displayVault() {
  PasswordVault *current = keeper;
  while (current != NULL) {
    printf("Name: %s, Password: %s\n", current->name, current->password);
    current = current->next;
  }
}

// The main guardian of our secrets
int main() {
  // Let's imagine we have a few passwords to store
  addToVault("Facebook", "password123");
  addToVault("Google", "password456");
  addToVault("Amazon", "password789");

  // Now let's say we need to retrieve the password for Google
  char *googlePassword = getPassword("Google");
  printf("Google password: %s\n", googlePassword);

  // And for fun, let's display all the entries in our vault
  printf("Displaying all vault entries:\n");
  displayVault();

  return 0;
}