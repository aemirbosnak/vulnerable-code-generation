//GEMINI-pro DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password database structure
typedef struct password_db {
  char username[50];
  char password[50];
  struct password_db *next;
} password_db;

// Function to create a new password database
password_db *create_password_db() {
  password_db *db = malloc(sizeof(password_db));
  db->username[0] = '\0';
  db->password[0] = '\0';
  db->next = NULL;
  return db;
}

// Function to add a new password to the database
void add_password(password_db *db, char *username, char *password) {
  password_db *new_password = malloc(sizeof(password_db));
  strcpy(new_password->username, username);
  strcpy(new_password->password, password);
  new_password->next = db->next;
  db->next = new_password;
}

// Function to find a password in the database
char *find_password(password_db *db, char *username) {
  password_db *current_password = db->next;
  while (current_password != NULL) {
    if (strcmp(current_password->username, username) == 0) {
      return current_password->password;
    }
    current_password = current_password->next;
  }
  return NULL;
}

// Function to print the password database
void print_password_db(password_db *db) {
  password_db *current_password = db->next;
  while (current_password != NULL) {
    printf("%s: %s\n", current_password->username, current_password->password);
    current_password = current_password->next;
  }
}

// Function to free the password database
void free_password_db(password_db *db) {
  password_db *current_password = db->next;
  while (current_password != NULL) {
    password_db *next_password = current_password->next;
    free(current_password);
    current_password = next_password;
  }
  free(db);
}

int main() {
  // Create a new password database
  password_db *db = create_password_db();

  // Add some passwords to the database
  add_password(db, "username1", "password1");
  add_password(db, "username2", "password2");
  add_password(db, "username3", "password3");

  // Print the password database
  print_password_db(db);

  // Find a password in the database
  char *password = find_password(db, "username2");
  printf("Password for username2: %s\n", password);

  // Free the password database
  free_password_db(db);

  return 0;
}