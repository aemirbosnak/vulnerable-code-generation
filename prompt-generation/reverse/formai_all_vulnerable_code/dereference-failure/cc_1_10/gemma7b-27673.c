//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
  char data[MAX_SIZE];
  struct Node* next;
} Node;

struct Index {
  Node* head;
  int size;
  char key[MAX_SIZE];
};

void insert(struct Index* index, char key, char data[]) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->data, data);
  newNode->next = NULL;

  if (index->head == NULL) {
    index->head = newNode;
  } else {
    Node* temp = index->head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  index->size++;
  strcpy(index->key, key);
}

void search(struct Index* index, char key) {
  Node* temp = index->head;
  while (temp) {
    if (strcmp(temp->data, key) == 0) {
      printf("Data: %s\n", temp->data);
      return;
    }
    temp = temp->next;
  }

  printf("Key not found.\n");
}

int main() {
  struct Index* index = (struct Index*)malloc(sizeof(struct Index));
  index->head = NULL;
  index->size = 0;

  insert(index, "a", "Apple");
  insert(index, "b", "Banana");
  insert(index, "c", "Cherry");

  search(index, "a");
  search(index, "b");
  search(index, "x");

  return 0;
}