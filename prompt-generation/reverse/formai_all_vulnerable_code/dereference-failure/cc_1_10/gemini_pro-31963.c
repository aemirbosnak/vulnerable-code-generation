//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the phone book
struct node {
  char *name;
  char *number;
  struct node *next;
};

// The head of the phone book
struct node *head = NULL;

// Add a new name and number to the phone book
void add_entry(char *name, char *number) {
  // Create a new node
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  // Copy the name and number into the new node
  new_node->name = strdup(name);
  new_node->number = strdup(number);

  // Add the new node to the head of the phone book
  new_node->next = head;
  head = new_node;
}

// Find a name in the phone book
struct node *find_entry(char *name) {
  // Start at the head of the phone book
  struct node *current_node = head;

  // While we haven't reached the end of the phone book
  while (current_node != NULL) {
    // If the current node's name matches the name we're looking for
    if (strcmp(current_node->name, name) == 0) {
      // Return the current node
      return current_node;
    }

    // Move to the next node in the phone book
    current_node = current_node->next;
  }

  // If we didn't find the name, return NULL
  return NULL;
}

// Print the phone book
void print_phone_book() {
  // Start at the head of the phone book
  struct node *current_node = head;

  // While we haven't reached the end of the phone book
  while (current_node != NULL) {
    // Print the current node's name and number
    printf("%s: %s\n", current_node->name, current_node->number);

    // Move to the next node in the phone book
    current_node = current_node->next;
  }
}

// Free the memory allocated for the phone book
void free_phone_book() {
  // Start at the head of the phone book
  struct node *current_node = head;

  // While we haven't reached the end of the phone book
  while (current_node != NULL) {
    // Free the current node's name and number
    free(current_node->name);
    free(current_node->number);

    // Move to the next node in the phone book
    struct node *next_node = current_node->next;

    // Free the current node
    free(current_node);

    // Move to the next node in the phone book
    current_node = next_node;
  }
}

// Main function
int main() {
  // Add some entries to the phone book
  add_entry("John Doe", "555-1212");
  add_entry("Jane Doe", "555-1213");
  add_entry("John Smith", "555-1214");

  // Print the phone book
  print_phone_book();

  // Free the memory allocated for the phone book
  free_phone_book();

  return 0;
}