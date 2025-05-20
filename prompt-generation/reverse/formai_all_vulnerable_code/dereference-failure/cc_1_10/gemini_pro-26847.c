//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CODE_LEN 100

typedef struct node {
  char c;
  int freq;
  struct node *left, *right;
} node_t;

typedef struct huff_code {
  char *code;
  int len;
} huff_code_t;

int compare(const void *a, const void *b) {
  return ((node_t *)a)->freq - ((node_t *)b)->freq;
}

node_t *create_node(char c, int freq) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->c = c;
  new_node->freq = freq;
  new_node->left = new_node->right = NULL;
  return new_node;
}

node_t *build_tree(char *str, int len) {
  // Create a frequency table
  int freq[256] = {0};
  for (int i = 0; i < len; i++) {
    freq[str[i]]++;
  }

  // Create a priority queue
  node_t *pq[len];
  int pq_size = 0;
  for (int i = 0; i < 256; i++) {
    if (freq[i] > 0) {
      pq[pq_size++] = create_node(i, freq[i]);
    }
  }

  // Build the Huffman tree
  while (pq_size > 1) {
    // Sort the priority queue
    qsort(pq, pq_size, sizeof(node_t *), compare);

    // Extract the two nodes with the lowest frequencies
    node_t *left = pq[0];
    node_t *right = pq[1];

    // Create a new node with the combined frequency
    node_t *new_node = create_node('\0', left->freq + right->freq);
    new_node->left = left;
    new_node->right = right;

    // Remove the two nodes from the priority queue
    memmove(pq, pq + 2, (pq_size - 2) * sizeof(node_t *));
    pq_size--;

    // Insert the new node into the priority queue
    pq[pq_size++] = new_node;
  }

  return pq[0];
}

void generate_codes(node_t *root, huff_code_t codes[256], char *code, int len) {
  if (root->left == NULL && root->right == NULL) {
    // Leaf node
    codes[root->c].code = (char *)malloc(len + 1);
    codes[root->c].code[len] = '\0';
    memcpy(codes[root->c].code, code, len);
    codes[root->c].len = len;
    return;
  }

  // Internal node
  char code_left[MAX_CODE_LEN], code_right[MAX_CODE_LEN];
  memcpy(code_left, code, len);
  memcpy(code_right, code, len);
  code_left[len] = '0';
  code_right[len] = '1';
  generate_codes(root->left, codes, code_left, len + 1);
  generate_codes(root->right, codes, code_right, len + 1);
}

int compress(char *str, char *compressed_str) {
  int len = strlen(str);

  // Build the Huffman tree
  node_t *root = build_tree(str, len);

  // Generate the Huffman codes
  huff_code_t codes[256];
  generate_codes(root, codes, "", 0);

  // Compress the string
  int compressed_len = 0;
  for (int i = 0; i < len; i++) {
    strcat(compressed_str, codes[str[i]].code);
    compressed_len += codes[str[i]].len;
  }

  // Free the Huffman tree
  node_t *q[len];
  int q_size = 0;
  q[q_size++] = root;
  while (q_size > 0) {
    node_t *curr = q[0];
    memmove(q, q + 1, (q_size - 1) * sizeof(node_t *));
    q_size--;
    if (curr->left != NULL) {
      q[q_size++] = curr->left;
    }
    if (curr->right != NULL) {
      q[q_size++] = curr->right;
    }
    free(curr);
  }

  return compressed_len;
}

void decompress(char *compressed_str, char *decompressed_str) {
  int len = strlen(compressed_str);

  // Build the Huffman tree
  node_t *root = build_tree(compressed_str, len);

  // Decompress the string
  node_t *curr = root;
  for (int i = 0; i < len; i++) {
    if (compressed_str[i] == '0') {
      curr = curr->left;
    } else {
      curr = curr->right;
    }

    if (curr->left == NULL && curr->right == NULL) {
      decompressed_str[i] = curr->c;
      curr = root;
    }
  }

  // Free the Huffman tree
  node_t *q[len];
  int q_size = 0;
  q[q_size++] = root;
  while (q_size > 0) {
    node_t *curr = q[0];
    memmove(q, q + 1, (q_size - 1) * sizeof(node_t *));
    q_size--;
    if (curr->left != NULL) {
      q[q_size++] = curr->left;
    }
    if (curr->right != NULL) {
      q[q_size++] = curr->right;
    }
    free(curr);
  }
}

int main() {
  char str[] = "abracadabra";
  char compressed_str[1000];
  char decompressed_str[1000];

  int compressed_len = compress(str, compressed_str);
  printf("Compressed string: %s\n", compressed_str);
  printf("Compressed length: %d\n", compressed_len);

  decompress(compressed_str, decompressed_str);
  printf("Decompressed string: %s\n", decompressed_str);

  return 0;
}