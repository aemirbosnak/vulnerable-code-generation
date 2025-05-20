//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 256

typedef struct Node {
  struct Node *left, *right;
  char symbol;
  int frequency;
} Node;

Node **createTree(char **symbols, int *frequency, int size) {
  Node **tree = (Node **)malloc(size * sizeof(Node));
  for (int i = 0; i < size; i++) {
    tree[i] = (Node *)malloc(sizeof(Node));
    tree[i]->left = NULL;
    tree[i]->right = NULL;
    tree[i]->symbol = symbols[i];
    tree[i]->frequency = frequency[i];
  }
  return tree;
}

void huffmanEncode(Node **tree, char *message) {
  for (int i = 0; message[i] != '\0'; i++) {
    Node *node = tree[message[i]];
    node->frequency++;
  }
}

void encode(Node **tree, char *message) {
  for (int i = 0; message[i] != '\0'; i++) {
    Node *node = tree[message[i]];
    printf("%c", node->symbol);
  }
}

int main() {
  char *symbols[] = {"a", "b", "c", "d", "e"};
  int frequency[] = {5, 3, 4, 2, 6};
  int size = 5;

  Node **tree = createTree(symbols, frequency, size);

  char message[] = "abcabc";
  huffmanEncode(tree, message);

  encode(tree, message);

  return 0;
}