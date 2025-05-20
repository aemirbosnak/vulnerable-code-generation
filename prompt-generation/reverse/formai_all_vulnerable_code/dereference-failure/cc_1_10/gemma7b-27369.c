//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char* data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, char* data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
  }
}

char* translateC(Node* head) {
  char* buffer = malloc(MAX_BUFFER_SIZE);
  int i = 0;

  for (Node* current = head; current; current = current->next) {
    switch (current->data[0]) {
      case 'a':
        buffer[i++] = 'A';
        break;
      case 'e':
        buffer[i++] = 'E';
        break;
      case 'i':
        buffer[i++] = 'I';
        break;
      case 'o':
        buffer[i++] = 'O';
        break;
      default:
        buffer[i++] = current->data[0];
    }
  }

  buffer[i] = '\0';
  return buffer;
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, "Alice");
  insertAtTail(&head, "Bob");
  insertAtTail(&head, "Charlie");

  char* translated = translateC(head);

  printf("%s\n", translated);

  free(translated);
  return 0;
}