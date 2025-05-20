//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node of a binary search tree (BST)
struct node {
  char* word;
  int count;
  struct node* left;
  struct node* right;
};

// Insert a word into the BST
struct node* insert(struct node* root, char* word) {
  if (root == NULL) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }

  int cmp = strcmp(word, root->word);
  if (cmp < 0) {
    root->left = insert(root->left, word);
  } else if (cmp > 0) {
    root->right = insert(root->right, word);
  } else {
    root->count++;
  }

  return root;
}

// Print the words in the BST in order
void inorder(struct node* root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%s: %d\n", root->word, root->count);
  inorder(root->right);
}

// Free the memory allocated for the BST
void free_tree(struct node* root) {
  if (root == NULL) {
    return;
  }

  free_tree(root->left);
  free_tree(root->right);
  free(root->word);
  free(root);
}

// Count the frequency of words in a text file
int main() {
  FILE* fp = fopen("text.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  struct node* root = NULL;

  char* word = NULL;
  size_t len = 0;
  ssize_t nread;
  while ((nread = getline(&word, &len, fp)) != -1) {
    // Remove non-alphabetic characters from the word
    for (char* c = word; *c != '\0'; c++) {
      *c = tolower(*c);
      if (!isalpha(*c)) {
        *c = '\0';
      }
    }

    // Insert the word into the BST
    if (strlen(word) > 0) {
      root = insert(root, word);
    }
  }

  free(word);
  fclose(fp);

  // Print the words in the BST in order
  inorder(root);

  // Free the memory allocated for the BST
  free_tree(root);

  return EXIT_SUCCESS;
}