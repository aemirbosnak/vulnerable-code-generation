//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: puzzling
// Enter the puzzling world of Huffman Coding!

#include <stdio.h>
#include <stdlib.h>

// A node in our Huffman Tree
typedef struct Node {
  int frequency;
  char data;
  struct Node *left, *right;
} Node;

// Compare nodes by frequency
int compareNodes(const void *a, const void *b) {
  Node *nodeA = (Node *)a;
  Node *nodeB = (Node *)b;
  return nodeA->frequency - nodeB->frequency;
}

// Build a Huffman Tree
Node *buildHuffmanTree(char *characters, int *frequencies, int size) {
  Node **nodes = (Node **)malloc(size * sizeof(Node *));

  // Create a node for each character
  for (int i = 0; i < size; i++) {
    nodes[i] = (Node *)malloc(sizeof(Node));
    nodes[i]->data = characters[i];
    nodes[i]->frequency = frequencies[i];
    nodes[i]->left = nodes[i]->right = NULL;
  }

  // Sort the nodes by frequency
  qsort(nodes, size, sizeof(Node *), compareNodes);

  // Build the tree
  while (size > 1) {
    // Get the two nodes with the lowest frequencies
    Node *left = nodes[0];
    Node *right = nodes[1];

    // Create a new node with the combined frequency
    Node *parent = (Node *)malloc(sizeof(Node));
    parent->frequency = left->frequency + right->frequency;
    parent->left = left;
    parent->right = right;

    // Remove the two nodes from the array
    nodes[0] = nodes[size - 1];
    nodes[1] = nodes[size - 2];
    size -= 2;

    // Insert the new node into the array
    int j;
    for (j = size - 1; j >= 0; j--) {
      if (nodes[j]->frequency <= parent->frequency) {
        break;
      }
    }
    for (int k = size; k > j + 1; k--) {
      nodes[k] = nodes[k - 1];
    }
    nodes[j + 1] = parent;
    size++;
  }

  return nodes[0];
}

// Encode a character using the Huffman Tree
void encodeCharacter(Node *root, char character, char *code, int *index) {
  if (root->left == NULL && root->right == NULL) {
    if (root->data == character) {
      code[*index] = '\0';
    }
    return;
  }

  if (root->left != NULL) {
    code[*index] = '0';
    *index += 1;
    encodeCharacter(root->left, character, code, index);
  }

  if (root->right != NULL) {
    code[*index] = '1';
    *index += 1;
    encodeCharacter(root->right, character, code, index);
  }
}

// Encode a string using the Huffman Tree
char *encodeString(Node *root, char *string) {
  int length = strlen(string);
  char *encodedString = (char *)malloc((length * 8 + 1) * sizeof(char));
  int index = 0;

  for (int i = 0; i < length; i++) {
    encodeCharacter(root, string[i], encodedString, &index);
  }

  return encodedString;
}

// Decode a string using the Huffman Tree
char *decodeString(Node *root, char *encodedString) {
  int length = strlen(encodedString);
  char *decodedString = (char *)malloc(length * sizeof(char));
  int index = 0;

  Node *current = root;
  for (int i = 0; i < length; i++) {
    if (encodedString[i] == '0') {
      current = current->left;
    } else if (encodedString[i] == '1') {
      current = current->right;
    }

    if (current->left == NULL && current->right == NULL) {
      decodedString[index] = current->data;
      index++;
      current = root;
    }
  }

  return decodedString;
}

// Free the Huffman Tree
void freeHuffmanTree(Node *root) {
  if (root->left != NULL) {
    freeHuffmanTree(root->left);
  }

  if (root->right != NULL) {
    freeHuffmanTree(root->right);
  }

  free(root);
}

int main() {
  // Here's a puzzling story:
  char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int frequencies[] = {45, 13, 12, 16, 9, 5, 8, 5, 12, 4, 2, 6, 3, 8, 10, 1, 6, 5, 2, 1, 1, 1, 1, 1, 1, 1};

  // Let's build a Huffman Tree to solve the puzzle:
  Node *root = buildHuffmanTree(characters, frequencies, 26);

  // Now, let's encode the secret message:
  char *encodedString = encodeString(root, "SECRETMESSAGE");
  printf("Encoded Message: %s\n", encodedString);

  // And finally, let's decode the puzzle and reveal the secret:
  char *decodedString = decodeString(root, encodedString);
  printf("Decoded Message: %s\n", decodedString);

  // Freeing the tree, we unravel the secrets and leave no traces behind:
  freeHuffmanTree(root);

  return 0;
}