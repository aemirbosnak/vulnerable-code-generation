//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256

typedef struct Node {
  char key[MAX_KEY_LENGTH];
  struct Node* next;
} Node;

Node* newNode(char* key) {
  Node* node = malloc(sizeof(Node));
  strcpy(node->key, key);
  node->next = NULL;
  return node;
}

void insert(Node* head, char* key) {
  if (head == NULL) {
    head = newNode(key);
  } else {
    Node* current = head;
    while (current->next) {
      if (strcmp(key, current->key) < 0) {
        current = current->next;
      }
    }
    insert(current->next, key);
  }
}

void encrypt(Node* head, char* message) {
  char* token = strtok(message, " ");
  while (token) {
    insert(head, token);
    token = strtok(NULL, " ");
  }
  printf("Encrypted message:\n");
  for (Node* current = head; current; current = current->next) {
    printf("%s ", current->key);
  }
  printf("\n");
}

int main() {
  Node* head = NULL;
  encrypt(head, "The quick brown fox jumps over the lazy dog.");
  return 0;
}