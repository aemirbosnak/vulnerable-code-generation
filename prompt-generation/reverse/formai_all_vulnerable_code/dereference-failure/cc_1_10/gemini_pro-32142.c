//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  char character;
  int frequency;
  struct _node *left;
  struct _node *right;
} node;

typedef struct {
  node *root;
  int size;
} huffTree;

huffTree *createHuffTree(char *message);
void printTree(huffTree *tree, char *prefix);
void encodeMessage(huffTree *tree, char *message, char **encodedMessage);
void decodeMessage(huffTree *tree, char *encodedMessage, char **message);

int main() {
  char *message = "May the wind be ever in your favor";
  huffTree *tree = createHuffTree(message);

  // Print the Huffman tree
  printf("Huffman tree:\n");
  printTree(tree, "");

  // Encode the message
  char *encodedMessage;
  encodeMessage(tree, message, &encodedMessage);

  // Print the encoded message
  printf("Encoded message:\n%s\n", encodedMessage);

  // Decode the message
  char *decodedMessage;
  decodeMessage(tree, encodedMessage, &decodedMessage);

  // Print the decoded message
  printf("Decoded message:\n%s\n", decodedMessage);

  return 0;
}

huffTree *createHuffTree(char *message) {
  // Create a frequency table
  int frequencyTable[256] = {0};
  for (int i = 0; i < strlen(message); i++) {
    frequencyTable[(unsigned char)message[i]]++;
  }

  // Create a priority queue of nodes
  node *nodes[256];
  int nodeCount = 0;
  for (int i = 0; i < 256; i++) {
    if (frequencyTable[i] > 0) {
      nodes[nodeCount] = malloc(sizeof(node));
      nodes[nodeCount]->character = (char)i;
      nodes[nodeCount]->frequency = frequencyTable[i];
      nodes[nodeCount]->left = NULL;
      nodes[nodeCount]->right = NULL;
      nodeCount++;
    }
  }

  // Create a Huffman tree
  while (nodeCount > 1) {
    // Find the two nodes with the lowest frequencies
    int min1 = -1;
    int min2 = -1;
    for (int i = 0; i < nodeCount; i++) {
      if (min1 == -1 || nodes[i]->frequency < nodes[min1]->frequency) {
        min1 = i;
      }
    }
    for (int i = 0; i < nodeCount; i++) {
      if (i == min1) continue;
      if (min2 == -1 || nodes[i]->frequency < nodes[min2]->frequency) {
        min2 = i;
      }
    }

    // Create a new node with the sum of the frequencies of the two nodes
    node *newNode = malloc(sizeof(node));
    newNode->character = '\0';
    newNode->frequency = nodes[min1]->frequency + nodes[min2]->frequency;
    newNode->left = nodes[min1];
    newNode->right = nodes[min2];

    // Replace the two nodes with the new node
    nodes[min1] = newNode;
    nodes[min2] = nodes[nodeCount - 1];
    nodeCount--;
  }

  // Create a Huffman tree from the root node
  huffTree *tree = malloc(sizeof(huffTree));
  tree->root = nodes[0];
  tree->size = strlen(message);

  return tree;
}

void printTree(huffTree *tree, char *prefix) {
  if (tree->root == NULL) return;

  if (tree->root->character != '\0') {
    printf("%s%c: %d\n", prefix, tree->root->character, tree->root->frequency);
    return;
  }

  printTree(tree->root->left, strcat(prefix, "0"));
  printTree(tree->root->right, strcat(prefix, "1"));
}

void encodeMessage(huffTree *tree, char *message, char **encodedMessage) {
  int encodedMessageLength = tree->size * 8;
  *encodedMessage = malloc(encodedMessageLength + 1);
  memset(*encodedMessage, '0', encodedMessageLength);
  (*encodedMessage)[encodedMessageLength] = '\0';

  int encodedMessageIndex = 0;
  for (int i = 0; i < strlen(message); i++) {
    char *code = malloc(8);
    memset(code, '0', 8);
    code[8] = '\0';

    node *node = tree->root;
    int bitIndex = 7;
    while (node->character != message[i]) {
      if (node->left != NULL && node->left->character == message[i]) {
        node = node->left;
        code[bitIndex] = '0';
      } else if (node->right != NULL && node->right->character == message[i]) {
        node = node->right;
        code[bitIndex] = '1';
      }
      bitIndex--;
    }

    for (int j = 0; j < 8; j++) {
      (*encodedMessage)[encodedMessageIndex] = code[j];
      encodedMessageIndex++;
    }

    free(code);
  }
}

void decodeMessage(huffTree *tree, char *encodedMessage, char **message) {
  int messageLength = strlen(encodedMessage) / 8;
  *message = malloc(messageLength + 1);
  memset(*message, '\0', messageLength + 1);

  int messageIndex = 0;
  node *node = tree->root;
  for (int i = 0; i < strlen(encodedMessage); i++) {
    if (encodedMessage[i] == '0') {
      node = node->left;
    } else if (encodedMessage[i] == '1') {
      node = node->right;
    }

    if (node->character != '\0') {
      (*message)[messageIndex] = node->character;
      messageIndex++;
      node = tree->root;
    }
  }
}