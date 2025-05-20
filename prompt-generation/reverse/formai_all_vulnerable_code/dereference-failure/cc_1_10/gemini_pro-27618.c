//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
// Linus Torvalds style Huffman Coding Implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
struct node {
  char data;
  int freq;
  struct node *left;
  struct node *right;
};

// Function to create a new node
struct node *create_node(char data, int freq) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->freq = freq;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Function to compare two nodes based on their frequencies
int compare(const void *a, const void *b) {
  struct node *node1 = (struct node *)a;
  struct node *node2 = (struct node *)b;
  return node1->freq - node2->freq;
}

// Function to build a Huffman tree
struct node *build_tree(char data[], int freq[], int size) {
  struct node *nodes[size];

  // Create nodes and initialize them with data and frequency
  for (int i = 0; i < size; i++) {
    nodes[i] = create_node(data[i], freq[i]);
  }

  // Sort the nodes based on their frequencies
  qsort(nodes, size, sizeof(struct node), compare);

  // Build the tree
  while (size > 1) {
    // Take the two nodes with the lowest frequencies
    struct node *left = nodes[0];
    struct node *right = nodes[1];

    // Create a new node with a frequency equal to the sum of the two nodes' frequencies
    struct node *parent = create_node('\0', left->freq + right->freq);

    // Set the left and right children of the parent node
    parent->left = left;
    parent->right = right;

    // Remove the two nodes from the list and add the parent node
    size--;
    nodes[0] = parent;
    qsort(nodes, size, sizeof(struct node), compare);
  }

  // Return the root of the tree
  return nodes[0];
}

// Function to print the Huffman codes
void print_codes(struct node *root, char code[], int top) {
  // If the node is a leaf, print the code
  if (root->left == NULL && root->right == NULL) {
    printf("%c: %s\n", root->data, code);
    return;
  }

  // If the node is not a leaf, recurse on the left and right children
  code[top] = '0';
  print_codes(root->left, code, top + 1);
  code[top] = '1';
  print_codes(root->right, code, top + 1);
}

// Function to encode a string
char *encode(struct node *root, char *str) {
  int top = 0;
  char *code = (char *)malloc(strlen(str) * sizeof(char));

  // Traverse the string and encode each character
  for (int i = 0; i < strlen(str); i++) {
    struct node *current_node = root;

    // Traverse the tree to find the code for the character
    while (current_node->left != NULL || current_node->right != NULL) {
      if (str[i] == current_node->data) {
        break;
      }

      if (str[i] < current_node->data) {
        current_node = current_node->left;
        code[top] = '0';
      } else {
        current_node = current_node->right;
        code[top] = '1';
      }

      top++;
    }
  }

  // Return the encoded string
  code[top] = '\0';
  return code;
}

// Function to decode a string
char *decode(struct node *root, char *code) {
  int top = 0;
  char *str = (char *)malloc(strlen(code) * sizeof(char));

  // Traverse the code and decode it
  while (code[top] != '\0') {
    struct node *current_node = root;

    // Traverse the tree to find the character for the code
    while (current_node->left != NULL || current_node->right != NULL) {
      if (code[top] == '0') {
        current_node = current_node->left;
      } else {
        current_node = current_node->right;
      }

      top++;
    }

    // Add the character to the decoded string
    str[top - 1] = current_node->data;
  }

  // Return the decoded string
  str[top - 1] = '\0';
  return str;
}

int main() {
  // Input string and frequencies
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data) / sizeof(data[0]);

  // Build the Huffman tree
  struct node *root = build_tree(data, freq, size);

  // Print the Huffman codes
  char code[size];
  printf("Huffman codes:\n");
  print_codes(root, code, 0);

  // Encode the string
  char *encoded_string = encode(root, "aabcdefa");
  printf("\nEncoded string: %s\n", encoded_string);

  // Decode the string
  char *decoded_string = decode(root, encoded_string);
  printf("\nDecoded string: %s\n", decoded_string);

  return 0;
}