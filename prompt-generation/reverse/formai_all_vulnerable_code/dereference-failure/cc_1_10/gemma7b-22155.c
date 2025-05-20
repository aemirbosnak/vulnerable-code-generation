//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
  char character;
  int frequency;
  struct Node* next;
} Node;

void insert(Node** head, char character, int frequency) {
  Node* newNode = malloc(sizeof(Node));
  newNode->character = character;
  newNode->frequency = frequency;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node* current = *head;
    Node* previous = NULL;
    while (current) {
      if (newNode->character < current->character) {
        previous = current;
        current = current->next;
      } else if (previous) {
        previous->next = newNode;
        break;
      }
    }
    if (previous) {
      previous->next = newNode;
    } else {
      *head = newNode;
    }
  }
}

void huffman_encode(Node* head) {
  char* prefix = malloc(MAX);
  prefix[0] = '\0';

  Node* current = head;
  while (current) {
    char code[MAX];
    int i = 0;
    for (Node* previous = head; previous; previous = previous->next) {
      if (current != previous) {
        code[i++] = '0';
      } else {
        code[i++] = '1';
      }
    }
    code[i] = '\0';
    printf("%c: %s\n", current->character, code);
  }

  free(prefix);
}

int main() {
  Node* head = NULL;
  insert(&head, 'a', 5);
  insert(&head, 'b', 3);
  insert(&head, 'c', 2);
  insert(&head, 'd', 4);

  huffman_encode(head);

  return 0;
}