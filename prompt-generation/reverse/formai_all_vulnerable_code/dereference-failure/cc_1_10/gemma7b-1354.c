//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char symbol;
  int frequency;
  struct Node* next;
} Node;

void insertNode(Node* node, char symbol, int frequency) {
  Node* newNode = malloc(sizeof(Node));
  newNode->symbol = symbol;
  newNode->frequency = frequency;
  newNode->next = NULL;

  if (node == NULL) {
    node = newNode;
  } else {
    Node* tempNode = node;
    while (tempNode->next) {
      tempNode = tempNode->next;
    }
    tempNode->next = newNode;
  }
}

void huffmanEncode(Node* node, char* message) {
  for (int i = 0; message[i] != '\0'; i++) {
    char symbol = message[i];
    int frequency = 0;
    for (int j = 0; message[j] != '\0'; j++) {
      if (symbol == message[j]) {
        frequency++;
      }
    }
    insertNode(node, symbol, frequency);
  }
}

void encode(Node* node, char* buffer) {
  for (int i = 0; node->symbol != '\0'; i++) {
    buffer[i] = node->symbol;
    node = node->next;
  }
}

int main() {
  Node* node = NULL;
  char message[] = "Hello, world!";
  huffmanEncode(node, message);

  char buffer[100];
  encode(node, buffer);

  printf("%s", buffer);

  return 0;
}