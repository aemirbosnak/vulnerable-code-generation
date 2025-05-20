//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct Node {
  char character;
  int frequency;
  struct Node* next;
} Node;

void huffman_encode(Node* root, FILE* file) {
  fprintf(file, "%c", root->character);
  fprintf(file, "%c", root->frequency);
  if (root->next) {
    huffman_encode(root->next, file);
  }
}

int main() {
  FILE* file = fopen("text.txt", "r");
  Node* root = NULL;
  char character;
  int frequency;

  while ((character = fgetc(file)) != EOF) {
    frequency = 1;
    Node* node = malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->next = NULL;

    if (root == NULL) {
      root = node;
    } else {
      Node* current = root;
      while (current->next) {
        current = current->next;
      }
      current->next = node;
    }
  }

  fclose(file);

  file = fopen("encoded.txt", "w");
  huffman_encode(root, file);
  fclose(file);

  return 0;
}