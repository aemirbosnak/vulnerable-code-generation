//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: mind-bending
// Dive into the labyrinth of binary search trees, where the order of elements dances to the whispers of a twisted logic.

#include <stdio.h>
#include <stdlib.h>

// Node: A twisted entity in this binary realm
typedef struct Node {
  int data;    // The core of this twisted existence
  struct Node *left, *right;  // Paths that lead to unknown depths
} Node;

// Insert: A ritual to summon nodes into the tree's twisted embrace
Node *insert(Node *root, int data) {
  if (root == NULL) {
    root = malloc(sizeof(Node));  // A new entity emerges from the void
    root->data = data;
    root->left = root->right = NULL;
    return root;
  }
  if (data < root->data)
    root->left = insert(root->left, data);  // Delve deeper into the left
  else if (data > root->data)
    root->right = insert(root->right, data);  // Ascend higher into the right
  return root;
}

// Search: A perilous quest through the chaotic depths
Node *search(Node *root, int data) {
  if (root == NULL)
    return NULL;  // The quest ends in futility
  if (root->data == data)
    return root;  // The prize is within reach
  if (data < root->data)
    return search(root->left, data);  // The journey continues to the left
  else
    return search(root->right, data);  // The path winds to the right
}

// Inorder: Unveiling the twisted secrets in an orderly flow
void inorder(Node *root) {
  if (root == NULL)
    return;
  inorder(root->left);  // Delve into the leftmost depths
  printf("%d ", root->data);  // Reveal the core of a twisted entity
  inorder(root->right);  // Ascend into the unknown heights
}

// Preorder: A chaotic dance of revelations
void preorder(Node *root) {
  if (root == NULL)
    return;
  printf("%d ", root->data);  // Unveiling the heart of a twisted being
  preorder(root->left);  // Exploring the leftward paths
  preorder(root->right);  // Venturing into the rightward unknown
}

// Postorder: A tale of remnants and the path less traveled
void postorder(Node *root) {
  if (root == NULL)
    return;
  postorder(root->left);  // Whispers of the past from the left
  postorder(root->right);  // Echoes of the future from the right
  printf("%d ", root->data);  // The final truth emerges from the depths
}

// Free: A ritual of unbinding, returning chaos to the void
void free_tree(Node *root) {
  if (root == NULL)
    return;
  free_tree(root->left);  // Freeing the leftward tendrils
  free_tree(root->right);  // Severing the rightward connections
  free(root);  // The final act of liberation, the node is no more
}

int main() {
  // Seed the chaotic realm with twisted entities
  Node *root = NULL;  // The genesis of our twisted realm
  int arr[] = {10, 5, 15, 3, 7, 12, 17, 1, 4, 6, 8, 11, 13, 16, 18};
  for (int i = 0; i < 15; i++)
    root = insert(root, arr[i]);

  // Unveiling the twisted secrets
  printf("\nInorder: The orderly flow revealing the chaos within: ");
  inorder(root);

  printf("\nPreorder: A chaotic dance of revelations: ");
  preorder(root);

  printf("\nPostorder: A tale of remnants and the path less traveled: ");
  postorder(root);

  // Searching for a lost soul in this chaotic realm
  int search_key = 13;
  Node *result = search(root, search_key);
  if (result == NULL)
    printf("\nThe key %d evades our grasp in this twisted realm.\n", search_key);
  else
    printf("\nThe key %d found its dwelling in the depths of this chaotic realm.\n", search_key);

  // Unbinding the twisted realm, returning chaos to the void
  free_tree(root);
  return 0;
}