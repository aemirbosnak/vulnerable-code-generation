//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_LENGTH 20

typedef struct node {
  char word[MAX_WORD_LENGTH];
  struct node *left;
  struct node *right;
} node;

node *create_node(char *word) {
  node *new_node = (node *)malloc(sizeof(node));
  strcpy(new_node->word, word);
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert(node **root, char *word) {
  if (*root == NULL) {
    *root = create_node(word);
  } else if (strcmp(word, (*root)->word) < 0) {
    insert(&(*root)->left, word);
  } else {
    insert(&(*root)->right, word);
  }
}

int search(node *root, char *word) {
  if (root == NULL) {
    return 0;
  } else if (strcmp(word, root->word) == 0) {
    return 1;
  } else if (strcmp(word, root->word) < 0) {
    return search(root->left, word);
  } else {
    return search(root->right, word);
  }
}

int main() {
  node *root = NULL;
  char word[MAX_WORD_LENGTH];

  // Insert some words into the tree
  insert(&root, "apple");
  insert(&root, "banana");
  insert(&root, "cherry");
  insert(&root, "dog");
  insert(&root, "elephant");

  // Search for a word in the tree
  printf("Enter a word to search for: ");
  scanf("%s", word);

  if (search(root, word)) {
    printf("The word '%s' was found in the tree.\n", word);
  } else {
    printf("The word '%s' was not found in the tree.\n", word);
  }

  return 0;
}