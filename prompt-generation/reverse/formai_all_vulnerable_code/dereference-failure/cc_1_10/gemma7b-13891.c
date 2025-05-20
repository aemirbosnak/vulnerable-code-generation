//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

struct Node {
  char character;
  int frequency;
  struct Node* left;
  struct Node* right;
};

struct Huffman_Tree {
  struct Node* root;
  pthread_mutex_t mutex;
  pthread_cond_t cond_var;
};

void insert_node(struct Huffman_Tree* tree, char character, int frequency) {
  pthread_mutex_lock(&tree->mutex);
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->character = character;
  newNode->frequency = frequency;
  newNode->left = NULL;
  newNode->right = NULL;

  if (tree->root == NULL) {
    tree->root = newNode;
  } else {
    struct Node* current = tree->root;
    struct Node* parent = NULL;
    while (current) {
      if (newNode->character < current->character) {
        parent = current;
        current = current->left;
      } else {
        parent = current;
        current = current->right;
      }
    }
    if (parent) {
      if (parent->left == NULL) {
        parent->left = newNode;
      } else {
        parent->right = newNode;
      }
    }
  }
  pthread_mutex_unlock(&tree->mutex);
}

void traverse_tree(struct Node* node) {
  printf("%c (%d) ", node->character, node->frequency);
  if (node->left) {
    traverse_tree(node->left);
  }
  if (node->right) {
    traverse_tree(node->right);
  }
}

int main() {
  struct Huffman_Tree* tree = malloc(sizeof(struct Huffman_Tree));
  tree->root = NULL;
  pthread_mutex_init(&tree->mutex, NULL);
  pthread_cond_init(&tree->cond_var, NULL);

  insert_node(tree, 'a', 10);
  insert_node(tree, 'b', 5);
  insert_node(tree, 'c', 15);
  insert_node(tree, 'd', 20);
  insert_node(tree, 'e', 8);

  traverse_tree(tree->root);

  return 0;
}