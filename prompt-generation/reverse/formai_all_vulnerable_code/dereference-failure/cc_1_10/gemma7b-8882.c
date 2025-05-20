//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct Node {
  char character;
  int frequency;
  struct Node* next;
} Node;

struct Node* insert(struct Node* head, char character, int frequency) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->character = character;
  newNode->frequency = frequency;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  struct Node* current = head;
  struct Node* previous = NULL;

  while (current) {
    if (newNode->character < current->character) {
      previous = current;
      current = current->next;
    } else if (previous) {
      previous->next = newNode;
      return head;
    }
  }

  previous->next = newNode;
  return head;
}

void huffman_encode(struct Node* head, char** encoding) {
  struct Node* current = head;
  while (current) {
    encoding[current->character] = "";
    int frequency = current->frequency;
    for (int i = 0; i < frequency; i++) {
      encoding[current->character] = encoding[current->character] + '0' + i;
    }
    current = current->next;
  }
}

int main() {
  struct Node* head = insert(NULL, 'a', 5);
  insert(head, 'b', 3);
  insert(head, 'c', 2);
  insert(head, 'd', 4);

  char** encoding = (char**)malloc(MAX * sizeof(char*));
  for (int i = 0; i < MAX; i++) {
    encoding[i] = (char*)malloc(MAX * sizeof(char));
  }

  huffman_encode(head, encoding);

  for (int i = 0; i < MAX; i++) {
    printf("%c: ", i + 1);
    printf("%s\n", encoding[i]);
  }

  return 0;
}