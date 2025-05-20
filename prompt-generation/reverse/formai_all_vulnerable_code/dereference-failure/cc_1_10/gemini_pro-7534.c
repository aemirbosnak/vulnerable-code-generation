//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the mailing list
typedef struct node {
  char *email;
  struct node *next;
} node;

// The head of the mailing list
node *head = NULL;

// Add an email to the mailing list
void add_email(char *email) {
  // Create a new node
  node *new_node = malloc(sizeof(node));
  new_node->email = strdup(email);
  new_node->next = NULL;

  // Add the new node to the end of the list
  if (head == NULL) {
    head = new_node;
  } else {
    node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Remove an email from the mailing list
void remove_email(char *email) {
  // Find the node with the given email
  node *current = head;
  node *previous = NULL;
  while (current != NULL && strcmp(current->email, email) != 0) {
    previous = current;
    current = current->next;
  }

  // If the node was found, remove it from the list
  if (current != NULL) {
    if (previous == NULL) {
      head = current->next;
    } else {
      previous->next = current->next;
    }
    free(current->email);
    free(current);
  }
}

// Print the mailing list
void print_mailing_list() {
  node *current = head;
  while (current != NULL) {
    printf("%s\n", current->email);
    current = current->next;
  }
}

// Free the mailing list
void free_mailing_list() {
  node *current = head;
  while (current != NULL) {
    node *next = current->next;
    free(current->email);
    free(current);
    current = next;
  }
}

int main() {
  // Add some emails to the mailing list
  add_email("john@example.com");
  add_email("mary@example.com");
  add_email("bob@example.com");

  // Print the mailing list
  printf("Current mailing list:\n");
  print_mailing_list();

  // Remove an email from the mailing list
  remove_email("bob@example.com");

  // Print the mailing list again
  printf("\nMailing list after removing bob@example.com:\n");
  print_mailing_list();

  // Free the mailing list
  free_mailing_list();

  return 0;
}