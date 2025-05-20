//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char c;
  int freq;
  struct node *left;
  struct node *right;
} node;

typedef struct {
  unsigned char *data;
  unsigned int size;
} bitstream;

void dfs(node *root, int bits, bitstream *bs) {
  if (root->left == NULL && root->right == NULL) {  
    for (int i = 0; i < bits; i++) {
      if (bs->size % 8 == 0) {
        bs->data = realloc(bs->data, bs->size + 1);
        bs->data[bs->size] = 0;
      }
      bs->data[bs->size] |= ((root->c >> i) & 1) << (bs->size % 8);
      bs->size += 1;
    }
    return;
  }
  dfs(root->left, bits + 1, bs);
  dfs(root->right, bits + 1, bs);
}

node *huffman(node *nodes[], int n) {
  for (int i = 0; i < n - 1; i++) {
    nodes[n + i] = malloc(sizeof(node));
    nodes[n + i]->freq = nodes[i]->freq + nodes[i + 1]->freq;
    nodes[n + i]->left = nodes[i];
    nodes[n + i]->right = nodes[i + 1];
    nodes[i] = NULL;
    nodes[i + 1] = nodes[n + i];
    int j = i + 1;
    while (j < n - 1 && nodes[j]->freq < nodes[j + 1]->freq) {
      node *t = nodes[j];
      nodes[j] = nodes[j + 1];
      nodes[j + 1] = t;
      j += 1;
    }
  }
  return nodes[n * 2 - 2];
}

bitstream *huffman_encode(char *text) {
  node *freq[256];
  for (int i = 0; i < 256; i++) {
    freq[i] = malloc(sizeof(node));
    freq[i]->c = i;
    freq[i]->freq = 0;
    freq[i]->left = NULL;
    freq[i]->right = NULL;
  }
  int n = strlen(text);
  for (int i = 0; i < n; i++) { freq[text[i]]->freq++; }
  node *root = huffman(freq, 256);
  bitstream *bs = malloc(sizeof(bitstream));
  bs->data = malloc(1);
  bs->size = 0;
  dfs(root, 0, bs);
  return bs;
}

char *huffman_decode(bitstream *bs) {
  int n = 0;
  node *stack[256];
  stack[0] = malloc(sizeof(node));
  node *root = stack[0];
  root->freq = 0;
  root->left = NULL;
  root->right = NULL;
  for (unsigned int i = 0; i < bs->size; i++) {
    for (int j = 0; j < 8; j++) {
      int bit = (bs->data[i] >> j) & 1;
      if (bit) {
        if (stack[n]->right == NULL) {
          stack[n]->right = malloc(sizeof(node));
          stack[n]->right->freq = 0;
          stack[n]->right->left = NULL;
          stack[n]->right->right = NULL;
        }
        stack[n + 1] = stack[n]->right;
        n += 1;
      } else {
        if (stack[n]->left == NULL) {
          stack[n]->left = malloc(sizeof(node));
          stack[n]->left->freq = 0;
          stack[n]->left->left = NULL;
          stack[n]->left->right = NULL;
        }
        stack[n + 1] = stack[n]->left;
        n += 1;
      }
    }
  }
  char *text = malloc(n / 8 + 1);
  node *node = root;
  int j = 0;
  for (unsigned int i = 0; i < bs->size; i++) {
    for (int k = 0; k < 8; k++) {
      int bit = (bs->data[i] >> k) & 1;
      if (bit) { node = node->right; }
      else { node = node->left; }
      if (node->left == NULL && node->right == NULL) {
        text[j] = node->c;
        node = root;
        j += 1;
      }
    }
  }
  text[n / 8] = 0;
  return text;
}

int main() {
  char *text = "puzzlingprogrammingpuzzles";
  bitstream *bs = huffman_encode(text);
  printf("Encoded data:\n");
  for (unsigned int i = 0; i < bs->size; i++) {
    printf("%d", (bs->data[i] >> 7) & 1);
    printf("%d", (bs->data[i] >> 6) & 1);
    printf("%d", (bs->data[i] >> 5) & 1);
    printf("%d", (bs->data[i] >> 4) & 1);
    printf("%d", (bs->data[i] >> 3) & 1);
    printf("%d", (bs->data[i] >> 2) & 1);
    printf("%d", (bs->data[i] >> 1) & 1);
    printf("%d ", bs->data[i] & 1);
    if (i % 16 == 15) { printf("\n"); }
  }
  printf("\n");
  char *decoded = huffman_decode(bs);
  printf("Decoded data:\n%s\n", decoded);
  free(bs->data);
  free(bs);
  free(decoded);
  return 0;
}