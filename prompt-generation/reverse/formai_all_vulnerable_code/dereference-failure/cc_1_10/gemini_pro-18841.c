//GEMINI-pro DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a linked list
typedef struct node {
  char data;
  struct node *next;
} node_t;

// Define the head and tail of the linked list
node_t *head = NULL;
node_t *tail = NULL;

// Function to insert a character into the linked list
void insert(char data) {
  // Create a new node
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  // If the linked list is empty, set the head and tail to the new node
  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    // Otherwise, add the new node to the end of the linked list
    tail->next = new_node;
    tail = new_node;
  }
}

// Function to delete a character from the linked list
void delete(char data) {
  // If the linked list is empty, do nothing
  if (head == NULL) {
    return;
  }

  // If the character to be deleted is the first character in the linked list, update the head
  if (head->data == data) {
    head = head->next;
    if (head == NULL) {
      tail = NULL;
    }
    return;
  }

  // Otherwise, traverse the linked list to find the character to be deleted
  node_t *current = head;
  while (current->next != NULL) {
    if (current->next->data == data) {
      break;
    }
    current = current->next;
  }

  // If the character to be deleted was found, update the linked list
  if (current->next != NULL) {
    if (current->next == tail) {
      tail = current;
    }
    current->next = current->next->next;
  }
}

// Function to print the linked list
void print_list() {
  // Traverse the linked list and print each character
  node_t *current = head;
  while (current != NULL) {
    printf("%c", current->data);
    current = current->next;
  }
  printf("\n");
}

// Function to read a file and insert each character into the linked list
void read_file(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  // Read each character from the file and insert it into the linked list
  char c;
  while ((c = fgetc(file)) != EOF) {
    insert(c);
  }

  // Close the file
  fclose(file);
}

// Function to write the linked list to a file
void write_file(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  // Write each character from the linked list to the file
  node_t *current = head;
  while (current != NULL) {
    fputc(current->data, file);
    current = current->next;
  }

  // Close the file
  fclose(file);
}

// Main function
int main() {
  // Read the file into the linked list
  read_file("input.txt");

  // Print the linked list
  printf("Original linked list: ");
  print_list();

  // Delete a character from the linked list
  delete('a');

  // Print the linked list
  printf("Linked list after deleting 'a': ");
  print_list();

  // Write the linked list to a file
  write_file("output.txt");

  return 0;
}