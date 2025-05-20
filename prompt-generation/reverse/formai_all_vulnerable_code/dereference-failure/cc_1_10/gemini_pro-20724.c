//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// The Wasteland Compression Algorithm (WCA)
// Developed by survivors of the nuclear apocalypse

// Compresses a string of characters using run-length encoding (RLE)
// and Huffman coding.

// Structures for RLE and Huffman coding
typedef struct RLE {
  char c;
  int count;
} RLE;

typedef struct Node {
  char c;
  int freq;
  struct Node *left, *right;
} Node;

// Function to compress a string using RLE
RLE *compress_rle(char *str) {
  int len = strlen(str);
  RLE *rle = malloc(sizeof(RLE) * len);
  int i, j = 0;
  rle[0].c = str[0];
  rle[0].count = 1;
  for (i = 1; i < len; i++) {
    if (str[i] == rle[j].c) {
      rle[j].count++;
    } else {
      j++;
      rle[j].c = str[i];
      rle[j].count = 1;
    }
  }
  return rle;
}

// Function to build a Huffman tree
Node *build_huffman_tree(char *str) {
  int len = strlen(str);
  int freq[256] = {0};
  for (int i = 0; i < len; i++) {
    freq[str[i]]++;
  }
  Node *queue[256];
  int front = 0, rear = 0;
  for (int i = 0; i < 256; i++) {
    if (freq[i] > 0) {
      Node *node = malloc(sizeof(Node));
      node->c = i;
      node->freq = freq[i];
      node->left = node->right = NULL;
      queue[rear++] = node;
    }
  }
  while (front < rear) {
    Node *left = queue[front++];
    Node *right = queue[front++];
    Node *parent = malloc(sizeof(Node));
    parent->c = -1;
    parent->freq = left->freq + right->freq;
    parent->left = left;
    parent->right = right;
    int j;
    for (j = front; j < rear; j++) {
      if (queue[j]->freq > parent->freq) {
        break;
      }
    }
    for (int k = rear; k > j; k--) {
      queue[k] = queue[k - 1];
    }
    queue[j] = parent;
    rear++;
  }
  return queue[front];
}

// Function to generate Huffman codes
char *generate_huffman_codes(Node *root, char *codes) {
  if (!root) {
    return codes;
  }
  if (!root->left && !root->right) {
    codes[strlen(codes)] = root->c;
    return codes;
  }
  codes[strlen(codes)] = '0';
  generate_huffman_codes(root->left, codes);
  codes[strlen(codes) - 1] = '1';
  generate_huffman_codes(root->right, codes);
  return codes;
}

// Function to compress a string using Huffman coding
char *compress_huffman(char *str, char *codes) {
  int len = strlen(str);
  char *compressed = malloc(len * 8);
  int i, j = 0;
  for (i = 0; i < len; i++) {
    char *code = &codes[str[i]];
    while (*code) {
      compressed[j++] = *code++;
    }
  }
  compressed[j] = '\0';
  return compressed;
}

// Function to decompress a string compressed using WCA
char *decompress_wca(RLE *rle, char *codes) {
  int len = 0;
  for (int i = 0; rle[i].c != '\0'; i++) {
    len += rle[i].count;
  }
  char *decompressed = malloc(len + 1);
  int i, j = 0;
  for (i = 0; rle[i].c != '\0'; i++) {
    char *code = &codes[rle[i].c];
    for (int k = 0; k < rle[i].count; k++) {
      while (*code) {
        decompressed[j++] = *code++;
      }
    }
  }
  decompressed[j] = '\0';
  return decompressed;
}

// Main function to test the compression and decompression functions
int main() {
  // Sample string to compress
  char *str = "This is a test string for the Wasteland Compression Algorithm.";

  // Compress the string using RLE
  RLE *rle = compress_rle(str);

  // Build the Huffman tree and generate Huffman codes
  Node *root = build_huffman_tree(str);
  char *codes = malloc(strlen(str) * 8);
  generate_huffman_codes(root, codes);

  // Compress the string using Huffman coding
  char *compressed = compress_huffman(str, codes);

  // Decompress the compressed string using WCA
  char *decompressed = decompress_wca(rle, codes);

  // Print the original, compressed, and decompressed strings
  printf("Original: %s\n", str);
  printf("Compressed: %s\n", compressed);
  printf("Decompressed: %s\n", decompressed);

  // Free the allocated memory
  free(rle);
  free(root);
  free(codes);
  free(compressed);
  free(decompressed);

  return 0;
}