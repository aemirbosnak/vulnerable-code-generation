//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256

typedef struct node {
  int freq;
  unsigned char symbol;
  struct node *left, *right;
} node_t;

typedef struct huffman_tree {
  node_t *root;
  int num_symbols;
} huffman_tree_t;

huffman_tree_t *create_huffman_tree(unsigned char *data, int len) {
  int freqs[MAX_SYMBOLS] = {0};
  for (int i = 0; i < len; i++) {
    freqs[data[i]]++;
  }

  node_t *nodes[MAX_SYMBOLS];
  int num_nodes = 0;
  for (int i = 0; i < MAX_SYMBOLS; i++) {
    if (freqs[i] > 0) {
      nodes[num_nodes++] = malloc(sizeof(node_t));
      nodes[num_nodes - 1]->freq = freqs[i];
      nodes[num_nodes - 1]->symbol = i;
      nodes[num_nodes - 1]->left = NULL;
      nodes[num_nodes - 1]->right = NULL;
    }
  }

  while (num_nodes > 1) {
    int min1 = -1, min2 = -1;
    for (int i = 0; i < num_nodes; i++) {
      if (min1 == -1 || nodes[i]->freq < nodes[min1]->freq) {
        min1 = i;
      }
    }
    for (int i = 0; i < num_nodes; i++) {
      if (min2 == -1 || (i != min1 && nodes[i]->freq < nodes[min2]->freq)) {
        min2 = i;
      }
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->freq = nodes[min1]->freq + nodes[min2]->freq;
    new_node->symbol = '\0';
    new_node->left = nodes[min1];
    new_node->right = nodes[min2];

    nodes[min1] = new_node;
    nodes[min2] = NULL;
    num_nodes--;
  }

  huffman_tree_t *tree = malloc(sizeof(huffman_tree_t));
  tree->root = nodes[0];
  tree->num_symbols = num_nodes;
  return tree;
}

void free_huffman_tree(huffman_tree_t *tree) {
  if (tree->root != NULL) {
    free_huffman_tree(tree->root->left);
    free_huffman_tree(tree->root->right);
    free(tree->root);
  }
  free(tree);
}

void print_huffman_tree(huffman_tree_t *tree, unsigned char *code, int len) {
  if (tree->root->left == NULL && tree->root->right == NULL) {
    printf("%c: ", tree->root->symbol);
    for (int i = 0; i < len; i++) {
      printf("%d", code[i]);
    }
    printf("\n");
    return;
  }

  code[len] = 0;
  print_huffman_tree(tree->root->left, code, len + 1);
  code[len] = 1;
  print_huffman_tree(tree->root->right, code, len + 1);
}

void encode_data(huffman_tree_t *tree, unsigned char *data, int len, unsigned char *encoded_data) {
  int encoded_len = 0;
  unsigned char code[MAX_SYMBOLS] = {0};
  for (int i = 0; i < len; i++) {
    node_t *node = tree->root;
    while (node->left != NULL && node->right != NULL) {
      if (data[i] == node->left->symbol) {
        node = node->left;
        code[encoded_len++] = 0;
      } else {
        node = node->right;
        code[encoded_len++] = 1;
      }
    }

    memcpy(encoded_data + encoded_len, code, encoded_len);
    encoded_len += encoded_len;
  }
}

void decode_data(huffman_tree_t *tree, unsigned char *encoded_data, int len, unsigned char *decoded_data) {
  int decoded_len = 0;
  node_t *node = tree->root;
  for (int i = 0; i < len; i++) {
    if (encoded_data[i] == 0) {
      node = node->left;
    } else {
      node = node->right;
    }

    if (node->left == NULL && node->right == NULL) {
      decoded_data[decoded_len++] = node->symbol;
      node = tree->root;
    }
  }
}

int main() {
  unsigned char data[] = "Huffman coding is a lossless data compression algorithm.";
  int len = strlen(data);

  huffman_tree_t *tree = create_huffman_tree(data, len);
  unsigned char code[MAX_SYMBOLS] = {0};
  print_huffman_tree(tree, code, 0);

  unsigned char encoded_data[len * 8];
  encode_data(tree, data, len, encoded_data);

  unsigned char decoded_data[len];
  decode_data(tree, encoded_data, len * 8, decoded_data);

  printf("Original data: %s\n", data);
  printf("Encoded data: ");
  for (int i = 0; i < len * 8; i++) {
    printf("%d", encoded_data[i]);
  }
  printf("\n");
  printf("Decoded data: %s\n", decoded_data);

  free_huffman_tree(tree);
  return 0;
}