//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// A node in a Huffman tree
typedef struct HuffmanNode {
  unsigned char character;
  unsigned int frequency;
  struct HuffmanNode *left, *right;
} HuffmanNode;

// A Huffman tree
typedef struct HuffmanTree {
  HuffmanNode *root;
} HuffmanTree;

// A compressed file
typedef struct CompressedFile {
  unsigned char *data;
  unsigned int size;
} CompressedFile;

// Create a new Huffman node
HuffmanNode *create_huffman_node(unsigned char character, unsigned int frequency) {
  HuffmanNode *node = malloc(sizeof(HuffmanNode));
  node->character = character;
  node->frequency = frequency;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Compare two Huffman nodes by frequency
int compare_huffman_nodes(const void *a, const void *b) {
  const HuffmanNode *node1 = (const HuffmanNode *)a;
  const HuffmanNode *node2 = (const HuffmanNode *)b;
  return node1->frequency - node2->frequency;
}

// Build a Huffman tree from a frequency table
HuffmanTree *build_huffman_tree(unsigned char *data, unsigned int size) {
  // Create a frequency table
  unsigned int frequency_table[256] = {0};
  for (unsigned int i = 0; i < size; i++) {
    frequency_table[data[i]]++;
  }

  // Create a priority queue of Huffman nodes
  HuffmanNode *nodes[256];
  for (unsigned int i = 0; i < 256; i++) {
    if (frequency_table[i] > 0) {
      nodes[i] = create_huffman_node(i, frequency_table[i]);
    }
  }

  // Sort the priority queue by frequency
  qsort(nodes, 256, sizeof(HuffmanNode *), compare_huffman_nodes);

  // Build the Huffman tree
  while (nodes[1] != NULL) {
    // Get the two nodes with the lowest frequencies
    HuffmanNode *node1 = nodes[0];
    HuffmanNode *node2 = nodes[1];

    // Create a new node with the combined frequency
    HuffmanNode *new_node = create_huffman_node(0, node1->frequency + node2->frequency);
    new_node->left = node1;
    new_node->right = node2;

    // Remove the two nodes with the lowest frequencies from the priority queue
    for (unsigned int i = 0; i < 256; i++) {
      if (nodes[i] == node1) {
        nodes[i] = nodes[255];
        nodes[255] = NULL;
      } else if (nodes[i] == node2) {
        nodes[i] = nodes[254];
        nodes[254] = NULL;
      }
    }

    // Insert the new node into the priority queue
    for (unsigned int i = 0; i < 256; i++) {
      if (nodes[i] == NULL) {
        nodes[i] = new_node;
        break;
      }
    }
  }

  // Create a Huffman tree
  HuffmanTree *tree = malloc(sizeof(HuffmanTree));
  tree->root = nodes[0];
  return tree;
}

// Free a Huffman tree
void free_huffman_tree(HuffmanTree *tree) {
  if (tree == NULL) {
    return;
  }
  free_huffman_tree(tree->root->left);
  free_huffman_tree(tree->root->right);
  free(tree->root);
  free(tree);
}

// Compress data using a Huffman tree
CompressedFile *compress_data(HuffmanTree *tree, unsigned char *data, unsigned int size) {
  // Create a compressed file
  CompressedFile *compressed_file = malloc(sizeof(CompressedFile));
  compressed_file->data = malloc(size);
  compressed_file->size = 0;

  // Compress the data
  for (unsigned int i = 0; i < size; i++) {
    unsigned char character = data[i];
    HuffmanNode *node = tree->root;
    while (node->left != NULL && node->right != NULL) {
      if (character & 1) {
        node = node->right;
      } else {
        node = node->left;
      }
      character >>= 1;
    }
    compressed_file->data[compressed_file->size++] = node->character;
  }

  return compressed_file;
}

// Free a compressed file
void free_compressed_file(CompressedFile *compressed_file) {
  if (compressed_file == NULL) {
    return;
  }
  free(compressed_file->data);
  free(compressed_file);
}

// Decompress data using a Huffman tree
unsigned char *decompress_data(HuffmanTree *tree, CompressedFile *compressed_file) {
  // Create a decompressed file
  unsigned char *decompressed_data = malloc(compressed_file->size * 8);
  unsigned int decompressed_size = 0;

  // Decompress the data
  unsigned char character = compressed_file->data[0];
  unsigned int bit_index = 7;
  HuffmanNode *node = tree->root;
  while (decompressed_size < compressed_file->size * 8) {
    if (character & (1 << bit_index)) {
      node = node->right;
    } else {
      node = node->left;
    }
    if (node->left == NULL && node->right == NULL) {
      decompressed_data[decompressed_size++] = node->character;
      node = tree->root;
    }
    bit_index--;
    if (bit_index == -1) {
      bit_index = 7;
      character = compressed_file->data[++compressed_file->size];
    }
  }

  return decompressed_data;
}

// Print a Huffman tree
void print_huffman_tree(HuffmanTree *tree, unsigned int depth) {
  if (tree == NULL) {
    return;
  }
  if (tree->root->left == NULL && tree->root->right == NULL) {
    printf("%c: %d\n", tree->root->character, tree->root->frequency);
    return;
  }
  printf("%d:\n", depth);
  print_huffman_tree(tree->root->left, depth + 1);
  print_huffman_tree(tree->root->right, depth + 1);
}

// Print a compressed file
void print_compressed_file(CompressedFile *compressed_file) {
  for (unsigned int i = 0; i < compressed_file->size; i++) {
    printf("%02X ", compressed_file->data[i]);
  }
  printf("\n");
}

// Print a decompressed file
void print_decompressed_file(unsigned char *decompressed_data, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    printf("%c", decompressed_data[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Get the input data
  unsigned char data[] = "This is a test of the Huffman compression algorithm.";
  unsigned int size = strlen(data);

  // Build a Huffman tree
  HuffmanTree *tree = build_huffman_tree(data, size);

  // Print the Huffman tree
  print_huffman_tree(tree, 0);

  // Compress the data
  CompressedFile *compressed_file = compress_data(tree, data, size);

  // Print the compressed file
  print_compressed_file(compressed_file);

  // Decompress the data
  unsigned char *decompressed_data = decompress_data(tree, compressed_file);

  // Print the decompressed file
  print_decompressed_file(decompressed_data, size);

  // Free the Huffman tree
  free_huffman_tree(tree);

  // Free the compressed file
  free_compressed_file(compressed_file);

  // Free the decompressed file
  free(decompressed_data);

  return 0;
}