//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: romantic
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

// Add a new email to the mailing list
void add_email(char *email) {
  // Create a new node
  node *new_node = malloc(sizeof(node));
  new_node->email = strdup(email);
  new_node->next = NULL;

  // Add the new node to the beginning of the list
  new_node->next = head;
  head = new_node;
}

// Send a message to all the emails in the mailing list
void send_message(char *message) {
  // Iterate over the list and send the message to each email
  node *current_node = head;
  while (current_node != NULL) {
    printf("Sending message to %s\n", current_node->email);
    current_node = current_node->next;
  }
}

// Print the mailing list
void print_mailing_list() {
  // Iterate over the list and print each email
  node *current_node = head;
  while (current_node != NULL) {
    printf("%s\n", current_node->email);
    current_node = current_node->next;
  }
}

// Free the mailing list
void free_mailing_list() {
  // Iterate over the list and free each node
  node *current_node = head;
  while (current_node != NULL) {
    node *next_node = current_node->next;
    free(current_node->email);
    free(current_node);
    current_node = next_node;
  }
}

int main() {
  // Add some emails to the mailing list
  add_email("john@example.com");
  add_email("mary@example.com");
  add_email("bob@example.com");

  // Send a message to the mailing list
  send_message("Hello, world!");

  // Print the mailing list
  print_mailing_list();

  // Free the mailing list
  free_mailing_list();

  return 0;
}