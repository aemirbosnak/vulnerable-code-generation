//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
  struct Node* left;
  struct Node* right;
  char character;
  int frequency;
} Node;

Node* insert(Node* node, char character, int frequency);
void huffman_encode(Node* root, char* message);
void huffman_decode(Node* root, char* message);

int main() {
  char message[] = "This is a sample message for huffman coding.";
  Node* root = NULL;
  root = insert(root, 'a', 5);
  root = insert(root, 'e', 3);
  root = insert(root, 'h', 2);
  root = insert(root, 'i', 2);
  root = insert(root, 'n', 2);
  root = insert(root, 'o', 2);
  root = insert(root, 'r', 2);
  root = insert(root, 's', 3);
  root = insert(root, 't', 2);
  root = insert(root, 'y', 1);
  huffman_encode(root, message);
  huffman_decode(root, message);

  return 0;
}

Node* insert(Node* node, char character, int frequency) {
  if (node == NULL) {
    node = malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->character = character;
    node->frequency = frequency;
  } else if (frequency < node->frequency) {
    node->left = insert(node->left, character, frequency);
  } else {
    node->right = insert(node->right, character, frequency);
  }

  return node;
}

void huffman_encode(Node* root, char* message) {
  char* encoded_message = malloc(strlen(message) * 2);
  int i = 0;
  for (i = 0; message[i] != '\0'; i++) {
    Node* current_node = root;
    while (current_node) {
      if (message[i] == current_node->character) {
        encoded_message[2*i] = current_node->left->character;
        encoded_message[2*i + 1] = current_node->right->character;
        break;
      } else if (message[i] < current_node->character) {
        current_node = current_node->left;
      } else {
        current_node = current_node->right;
      }
    }
  }

  printf("%s", encoded_message);
  free(encoded_message);
}

void huffman_decode(Node* root, char* message) {
  char* decoded_message = malloc(strlen(message) * 2);
  int i = 0;
  Node* current_node = root;
  for (i = 0; message[i] != '\0'; i++) {
    if (current_node->left->character == message[i] && current_node->right->character == message[i]) {
      decoded_message[2*i] = current_node->character;
      current_node = root;
    } else if (message[i] < current_node->character) {
      current_node = current_node->left;
    } else {
      current_node = current_node->right;
    }
  }

  printf("%s", decoded_message);
  free(decoded_message);
}