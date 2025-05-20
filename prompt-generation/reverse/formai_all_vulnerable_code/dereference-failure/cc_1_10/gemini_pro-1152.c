//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *word;
  int count;
  struct node *left;
  struct node *right;
} node;

node *create_node(char *word) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->word = strdup(word);
  new_node->count = 1;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(node **root, char *word) {
  if (*root == NULL) {
    *root = create_node(word);
  } else if (strcmp((*root)->word, word) > 0) {
    insert_node(&(*root)->left, word);
  } else if (strcmp((*root)->word, word) < 0) {
    insert_node(&(*root)->right, word);
  } else {
    (*root)->count++;
  }
}

void print_tree(node *root) {
  if (root == NULL) {
    return;
  }
  print_tree(root->left);
  printf("%s: %d\n", root->word, root->count);
  print_tree(root->right);
}

void free_tree(node *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root->word);
  free(root);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  char word[1024];
  node *root = NULL;

  while (fscanf(fp, "%s", word) != EOF) {
    insert_node(&root, word);
  }

  fclose(fp);

  print_tree(root);
  free_tree(root);

  return 0;
}