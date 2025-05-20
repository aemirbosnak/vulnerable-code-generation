//GEMINI-pro DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A happy password management system!

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password
typedef struct {
  char *name;
  char *password;
} Password;

// Create an array of passwords
Password passwords[NUM_PASSWORDS];

// Get a password from the user
Password get_password(char *name) {
  Password password;
  password.name = name;

  char *input = malloc(MAX_PASSWORD_LENGTH);

  printf("Enter a password for %s: ", name);
  scanf("%s", input);

  password.password = input;

  return password;
}

// Store a password in the array
void store_password(Password password) {
  int i;

  // Find an empty slot in the array
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].name == NULL) {
      passwords[i] = password;
      break;
    }
  }
}

// Retrieve a password from the array
Password *retrieve_password(char *name) {
  int i;

  // Find the password in the array
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (strcmp(passwords[i].name, name) == 0) {
      return &passwords[i];
    }
  }

  // Return NULL if the password was not found
  return NULL;
}

// Print the passwords
void print_passwords() {
  int i;

  printf("Your passwords:\n");

  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].name != NULL) {
      printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
  }
}

// Main function
int main() {
  int choice;

  // Get the user's choice
  do {
    printf("1. Store a password\n");
    printf("2. Retrieve a password\n");
    printf("3. Print all passwords\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
      case 1:
        store_password(get_password("Enter a name for the password: "));
        break;
      case 2:
        {
          Password *password = retrieve_password("Enter the name of the password to retrieve: ");
          if (password == NULL) {
            printf("Password not found.\n");
          } else {
            printf("Password: %s\n", password->password);
          }
        }
        break;
      case 3:
        print_passwords();
        break;
      case 4:
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 4);

  return 0;
}