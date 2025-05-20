//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the node structure
typedef struct node {
  char *email;
  struct node *next;
} node_t;

// Declare the mailing list head
node_t *head = NULL;

// Add a new email to the mailing list
void add_email(char *email) {
  // Create a new node
  node_t *new_node = malloc(sizeof(node_t));

  // Copy the email address into the new node
  new_node->email = strdup(email);

  // Set the next pointer of the new node to NULL
  new_node->next = NULL;

  // If the mailing list is empty, set the head pointer to the new node
  if (head == NULL) {
    head = new_node;
  } else {
    // Otherwise, add the new node to the end of the mailing list
    node_t *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

// Print the mailing list
void print_mailing_list() {
  // Iterate over the mailing list and print each email address
  node_t *current_node = head;
  while (current_node != NULL) {
    printf("%s\n", current_node->email);
    current_node = current_node->next;
  }
}

// Free the mailing list
void free_mailing_list() {
  // Iterate over the mailing list and free each node
  node_t *current_node = head;
  while (current_node != NULL) {
    node_t *next_node = current_node->next;
    free(current_node->email);
    free(current_node);
    current_node = next_node;
  }
}

// Main function
int main(int argc, char **argv) {
  // Add some email addresses to the mailing list
  add_email("john@example.com");
  add_email("jane@example.com");
  add_email("bob@example.com");

  // Print the mailing list
  printf("Mailing list:\n");
  print_mailing_list();

  // Free the mailing list
  free_mailing_list();

  return 0;
}