//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 20

typedef struct node {
  int frequency;
  char character;
  struct node *left;
  struct node *right;
} node;

typedef struct code {
  char character;
  char *code;
} code;

void create_tree(node **root, char *characters, int *frequencies, int size) {
  int i;
  node *temp;

  // Create a forest of single-node trees
  for (i = 0; i < size; i++) {
    temp = (node *)malloc(sizeof(node));
    temp->frequency = frequencies[i];
    temp->character = characters[i];
    temp->left = NULL;
    temp->right = NULL;
    root[i] = temp;
  }

  // Build the Huffman tree
  while (size > 1) {
    // Find the two nodes with the lowest frequencies
    node **min1 = &root[0];
    node **min2 = &root[1];
    for (i = 2; i < size; i++) {
      if (root[i]->frequency < (*min1)->frequency) {
        min2 = min1;
        min1 = &root[i];
      } else if (root[i]->frequency < (*min2)->frequency) {
        min2 = &root[i];
      }
    }

    // Create a new node with the sum of the frequencies of the two nodes
    temp = (node *)malloc(sizeof(node));
    temp->frequency = (*min1)->frequency + (*min2)->frequency;
    temp->character = '\0';
    temp->left = *min1;
    temp->right = *min2;

    // Remove the two nodes from the forest
    for (i = 0; i < size; i++) {
      if (root[i] == *min1 || root[i] == *min2) {
        root[i] = temp;
        size--;
        break;
      }
    }
  }

  *root = root[0];
}

void create_codes(node *root, code *codes, char *code, int code_length) {
  if (root->left == NULL && root->right == NULL) {
    codes[root->character].code = malloc(code_length + 1);
    strcpy(codes[root->character].code, code);
    return;
  }

  if (root->left != NULL) {
    code[code_length] = '0';
    create_codes(root->left, codes, code, code_length + 1);
  }

  if (root->right != NULL) {
    code[code_length] = '1';
    create_codes(root->right, codes, code, code_length + 1);
  }
}

void print_codes(code *codes, int size) {
  int i;

  for (i = 0; i < size; i++) {
    if (codes[i].code != NULL) {
      printf("%c: %s\n", codes[i].character, codes[i].code);
    }
  }
}

void free_tree(node *root) {
  if (root->left != NULL) {
    free_tree(root->left);
  }

  if (root->right != NULL) {
    free_tree(root->right);
  }

  free(root);
}

void free_codes(code *codes, int size) {
  int i;

  for (i = 0; i < size; i++) {
    if (codes[i].code != NULL) {
      free(codes[i].code);
    }
  }
}

int main(void) {
  char characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  int frequencies[] = {5, 9, 12, 13, 16, 45, 67, 34, 23, 43};
  int size = 10;

  node *root = NULL;
  create_tree(&root, characters, frequencies, size);

  code codes[size];
  char code[MAX_CODE_LENGTH];
  create_codes(root, codes, code, 0);

  print_codes(codes, size);

  free_tree(root);
  free_codes(codes, size);

  return 0;
}