//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The master password — the key to the kingdom
#define MASTER_PASSWORD "xyzzy"

// A node in the doubly-linked list of passwords
typedef struct password_node {
  char *site;
  char *username;
  char *password;
  struct password_node *prev;
  struct password_node *next;
} password_node;

// The head and tail of the doubly-linked list of passwords
password_node *head = NULL;
password_node *tail = NULL;

// Prototypes for the functions in this program
void add_password(char *site, char *username, char *password);
void delete_password(char *site);
void print_passwords();
void free_passwords();

// The main function
int main() {
  // Get the master password from the user
  char *master_password = getpass("Master password: ");

  // Check if the master password is correct
  if (strcmp(master_password, MASTER_PASSWORD) != 0) {
    printf("Incorrect master password.\n");
    return 1;
  }

  // Get the user's input
  int choice;
  char *site;
  char *username;
  char *password;
  while (1) {
    printf("1. Add a password\n");
    printf("2. Delete a password\n");
    printf("3. Print all passwords\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Process the user's choice
    switch (choice) {
      case 1:
        printf("Enter the site: ");
        scanf("%s", site);
        printf("Enter the username: ");
        scanf("%s", username);
        printf("Enter the password: ");
        scanf("%s", password);
        add_password(site, username, password);
        break;
      case 2:
        printf("Enter the site: ");
        scanf("%s", site);
        delete_password(site);
        break;
      case 3:
        print_passwords();
        break;
      case 4:
        free_passwords();
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}

// Adds a password to the doubly-linked list
void add_password(char *site, char *username, char *password) {
  // Create a new node
  password_node *new_node = malloc(sizeof(password_node));
  new_node->site = strdup(site);
  new_node->username = strdup(username);
  new_node->password = strdup(password);
  new_node->prev = NULL;
  new_node->next = NULL;

  // If the list is empty, make the new node the head and tail
  if (head == NULL) {
    head = new_node;
    tail = new_node;
  }
  // Otherwise, add the new node to the end of the list
  else {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
}

// Deletes a password from the doubly-linked list
void delete_password(char *site) {
  // Find the node to delete
  password_node *current_node = head;
  while (current_node != NULL) {
    if (strcmp(current_node->site, site) == 0) {
      break;
    }
    current_node = current_node->next;
  }

  // If the node was found, delete it
  if (current_node != NULL) {
    if (current_node == head) {
      head = current_node->next;
    }
    else {
      current_node->prev->next = current_node->next;
    }
    if (current_node == tail) {
      tail = current_node->prev;
    }
    else {
      current_node->next->prev = current_node->prev;
    }
    free(current_node->site);
    free(current_node->username);
    free(current_node->password);
    free(current_node);
  }
}

// Prints all of the passwords in the doubly-linked list
void print_passwords() {
  // Traverse the list and print each password
  password_node *current_node = head;
  while (current_node != NULL) {
    printf("Site: %s\n", current_node->site);
    printf("Username: %s\n", current_node->username);
    printf("Password: %s\n\n", current_node->password);
    current_node = current_node->next;
  }
}

// Frees all of the passwords in the doubly-linked list
void free_passwords() {
  // Traverse the list and free each node
  password_node *current_node = head;
  while (current_node != NULL) {
    password_node *next_node = current_node->next;
    free(current_node->site);
    free(current_node->username);
    free(current_node->password);
    free(current_node);
    current_node = next_node;
  }

  // Set the head and tail to NULL
  head = NULL;
  tail = NULL;
}