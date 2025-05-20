//GEMINI-pro DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the password list
typedef struct password_node {
  char *website;
  char *username;
  char *password;
  struct password_node *next;
} password_node;

// The head of the password list
password_node *head = NULL;

// Add a new password to the list
void add_password(char *website, char *username, char *password) {
  // Create a new node
  password_node *new_node = malloc(sizeof(password_node));

  // Set the node's values
  new_node->website = strdup(website);
  new_node->username = strdup(username);
  new_node->password = strdup(password);
  new_node->next = NULL;

  // Add the node to the list
  if (head == NULL) {
    head = new_node;
  } else {
    password_node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Get a password from the list
char *get_password(char *website) {
  // Find the node with the matching website
  password_node *current = head;
  while (current != NULL) {
    if (strcmp(current->website, website) == 0) {
      return current->password;
    }
    current = current->next;
  }

  // No matching node found
  return NULL;
}

// Print the password list
void print_passwords() {
  password_node *current = head;
  while (current != NULL) {
    printf("%s: %s\n", current->website, current->password);
    current = current->next;
  }
}

// Free the password list
void free_passwords() {
  password_node *current = head;
  while (current != NULL) {
    password_node *next = current->next;
    free(current->website);
    free(current->username);
    free(current->password);
    free(current);
    current = next;
  }
}

int main() {
  // Add some passwords to the list
  add_password("google.com", "johndoe", "password123");
  add_password("facebook.com", "janedoe", "password456");
  add_password("twitter.com", "johndoe123", "password789");

  // Get a password from the list
  char *password = get_password("facebook.com");

  // Print the password
  printf("Password: %s\n", password);

  // Print the password list
  print_passwords();

  // Free the password list
  free_passwords();

  return 0;
}