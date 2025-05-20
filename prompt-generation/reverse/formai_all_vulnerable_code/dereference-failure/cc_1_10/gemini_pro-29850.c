//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: immersive
// Welcome to the immersive world of C Database Indexing System!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our database is an array of records
typedef struct {
  int id;
  char name[50];
  char email[50];
  char phone[20];
} Record;

// The index is a binary search tree
typedef struct Node {
  Record record;
  struct Node *left;
  struct Node *right;
} Node;

// Create a new node
Node *createNode(Record record) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->record = record;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Insert a new node into the tree
Node *insertNode(Node *root, Record record) {
  if (root == NULL) {
    return createNode(record);
  } else if (record.id < root->record.id) {
    root->left = insertNode(root->left, record);
  } else if (record.id > root->record.id) {
    root->right = insertNode(root->right, record);
  }
  return root;
}

// Search for a record in the tree
Node *searchNode(Node *root, int id) {
  if (root == NULL) {
    return NULL;
  } else if (id == root->record.id) {
    return root;
  } else if (id < root->record.id) {
    return searchNode(root->left, id);
  } else {
    return searchNode(root->right, id);
  }
}

// Print the tree in order
void printTree(Node *root) {
  if (root != NULL) {
    printTree(root->left);
    printf("%d %s %s %s\n", root->record.id, root->record.name, root->record.email, root->record.phone);
    printTree(root->right);
  }
}

// Free the tree
void freeTree(Node *root) {
  if (root != NULL) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

// Main function
int main() {
  // Create a new database
  Record records[] = {
    {1, "John Doe", "johndoe@example.com", "+1-555-1212"},
    {2, "Jane Doe", "janedoe@example.com", "+1-555-1213"},
    {3, "Peter Parker", "peterparker@example.com", "+1-555-1214"},
    {4, "Mary Jane Watson", "maryjanewatson@example.com", "+1-555-1215"},
    {5, "Bruce Wayne", "brucewayne@example.com", "+1-555-1216"},
  };
  int numRecords = sizeof(records) / sizeof(Record);

  // Create a binary search tree index
  Node *root = NULL;
  for (int i = 0; i < numRecords; i++) {
    root = insertNode(root, records[i]);
  }

  // Search for a record in the tree
  int id = 3;
  Node *record = searchNode(root, id);
  if (record != NULL) {
    printf("Found record: %d %s %s %s\n", record->record.id, record->record.name, record->record.email, record->record.phone);
  } else {
    printf("Record not found.\n");
  }

  // Print the tree in order
  printf("Printing the tree:\n");
  printTree(root);

  // Free the tree
  freeTree(root);

  return 0;
}