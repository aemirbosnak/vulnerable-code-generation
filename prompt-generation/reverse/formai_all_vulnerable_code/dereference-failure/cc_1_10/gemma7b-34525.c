//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
  char data[MAX_SIZE];
  struct Node* next;
} Node;

struct Index {
  Node* head;
  int size;
  time_t timestamp;
};

void insert(struct Index* index, char data[]) {
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
  index->timestamp = time(NULL);
}

char search(struct Index* index, char data[]) {
  Node* temp = index->head;
  while (temp) {
    if (strcmp(temp->data, data) == 0) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int main() {
  struct Index* index = (struct Index*)malloc(sizeof(struct Index));
  index->head = NULL;
  index->size = 0;
  index->timestamp = time(NULL);

  insert(index, "John Doe");
  insert(index, "Jane Doe");
  insert(index, "Jack Doe");

  if (search(index, "Jane Doe")) {
    printf("Jane Doe is found.\n");
  }

  return 0;
}