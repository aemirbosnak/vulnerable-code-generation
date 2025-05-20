//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Define a Cryptic struct for linked list node
struct CrypNode {
  int data;
  char pass[8];
  struct CrypNode *next;
};

// Function to create a Cryptic linked list node
struct CrypNode *create_cryp_node(int data, char pass[]) {
  struct CrypNode *new_node = (struct CrypNode *)malloc(sizeof(struct CrypNode));
  new_node->data = data;
  strcpy(new_node->pass, pass);
  new_node->next = NULL;
  return new_node;
}

// Function to insert a Cryptic node at the beginning of the linked list
void insert_cryp_node(struct CrypNode **head_ref, int data, char pass[]) {
  struct CrypNode *new_node = create_cryp_node(data, pass);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Function to print the Cryptic linked list
void print_cryp_linked_list(struct CrypNode *node) {
  while (node != NULL) {
    printf("Crypto Data: %d | User Pass: %s\n", node->data, node->pass);
    node = node->next;
  }
}

// Function to search a node by the provided password
struct CrypNode *search_cryp_node_by_pass(struct CrypNode *node, char pass[]) {
  while (node != NULL) {
    if(strcmp(node->pass, pass) == 0) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

// Function to delete a specified node from the linked list
void delete_cryp_node(struct CrypNode **head_ref, char pass[]) {
  struct CrypNode *temp = *head_ref, *prev;

  if (temp != NULL && strcmp(temp->pass, pass) == 0) {
    *head_ref = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && strcmp(temp->pass, pass) != 0) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    return;
  }

  prev->next = temp->next;
  free(temp);
}

// Main function to execute the Cryptic linked list program
int main() {
  struct CrypNode *head = NULL;

  // Insert Cryptic nodes
  insert_cryp_node(&head, 10, "abc123");
  insert_cryp_node(&head, 20, "xyv789");
  insert_cryp_node(&head, 30, "qwe456");

  // Print the Cryptic linked list
  printf("Initial Crypto Linked List:\n");
  print_cryp_linked_list(head);

  // Search a node by the provided password
  struct CrypNode *search_node = search_cryp_node_by_pass(head, "xyv789");
  if(search_node != NULL) {
    printf("Found a node with the password: %s\n", search_node->pass);
  } else {
    printf("No node found with the provided password!\n");
  }

  // Delete a specified node from the linked list
  delete_cryp_node(&head, "abc123");

  // Print the updated Cryptic linked list
  printf("Updated Crypto Linked List:\n");
  print_cryp_linked_list(head);

  return 0;
}