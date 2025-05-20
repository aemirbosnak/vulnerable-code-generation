//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
  char **data;
  struct Node* next;
} Node;

Node* insert_node(Node* head, char** data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int search_index(Node* head, char* key) {
  for (Node* current = head; current; current = current->next) {
    for (int i = 0; i < MAX_INDEX_SIZE && current->data[i] != NULL; i++) {
      if (strcmp(current->data[i], key) == 0) {
        return i;
      }
    }
  }

  return -1;
}

int main() {
  Node* head = NULL;

  char** data = (char**)malloc(MAX_INDEX_SIZE * sizeof(char*));
  for (int i = 0; i < MAX_INDEX_SIZE; i++) {
    data[i] = (char*)malloc(100 * sizeof(char));
  }

  insert_node(head, data);

  search_index(head, "apple");

  return 0;
}