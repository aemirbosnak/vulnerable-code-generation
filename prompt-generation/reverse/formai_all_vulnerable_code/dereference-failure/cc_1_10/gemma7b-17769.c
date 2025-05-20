//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
  char data[MAX_INDEX_SIZE];
  struct Node* next;
} Node;

pthread_mutex_t mutex;

Node* head = NULL;

void insert(char* data) {
  pthread_mutex_lock(&mutex);

  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->data, data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  pthread_mutex_unlock(&mutex);
}

void search(char* data) {
  pthread_mutex_lock(&mutex);

  Node* temp = head;
  while (temp) {
    if (strcmp(temp->data, data) == 0) {
      printf("Data found: %s\n", temp->data);
      break;
    }
    temp = temp->next;
  }

  pthread_mutex_unlock(&mutex);
}

int main() {
  insert("John Doe");
  insert("Jane Doe");
  insert("Bill Smith");
  insert("Jack Bauer");

  search("Jane Doe");

  return 0;
}