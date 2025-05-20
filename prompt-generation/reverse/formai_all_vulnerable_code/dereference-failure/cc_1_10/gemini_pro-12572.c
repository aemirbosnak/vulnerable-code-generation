//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the binary tree
typedef struct node {
  char *item;                    // Name of the item
  int price;                     // Current price of the item
  struct node *left;              // Left child of the node
  struct node *right;             // Right child of the node
} node;

// Function to create a new node
node *create_node(char *item, int price) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->item = strdup(item);
  new_node->price = price;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Function to insert a new item into the binary tree
node *insert_item(node *root, char *item, int price) {
  if (root == NULL) {
    return create_node(item, price);
  } else if (strcmp(item, root->item) < 0) {
    root->left = insert_item(root->left, item, price);
  } else if (strcmp(item, root->item) > 0) {
    root->right = insert_item(root->right, item, price);
  }
  return root;
}

// Function to find the item with the highest price in the binary tree
node *find_max_price(node *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->right == NULL) {
    return root;
  } else {
    return find_max_price(root->right);
  }
}

// Function to print the items in the binary tree in order of their price
void print_items(node *root) {
  if (root == NULL) {
    return;
  }
  print_items(root->left);
  printf("%s: %d\n", root->item, root->price);
  print_items(root->right);
}

int main() {
  // Create the root of the binary tree
  node *root = NULL;

  // Insert some items into the binary tree
  root = insert_item(root, "Apple", 10);
  root = insert_item(root, "Orange", 15);
  root = insert_item(root, "Banana", 20);
  root = insert_item(root, "Grape", 25);
  root = insert_item(root, "Strawberry", 30);

  // Find the item with the highest price
  node *max_price_node = find_max_price(root);

  // Print the items in the binary tree in order of their price
  print_items(root);

  // Print the item with the highest price
  printf("The item with the highest price is: %s (%d)\n", max_price_node->item, max_price_node->price);

  return 0;
}