//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
  int data;
  struct Node* next;
};

struct Queue {
  struct Node* head;
  struct Node* tail;
};

void enqueue(struct Queue* queue, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (queue->head == NULL) {
    queue->head = newNode;
    queue->tail = newNode;
  } else {
    queue->tail->next = newNode;
    queue->tail = newNode;
  }
}

int dequeue(struct Queue* queue) {
  if (queue->head == NULL) {
    return -1;
  }

  struct Node* temp = queue->head;
  queue->head = queue->head->next;
  free(temp);

  return queue->head->data;
}

int main() {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->head = NULL;
  queue->tail = NULL;

  int i = 0;
  for (i = 0; i < MAX; i++) {
    enqueue(queue, i + 1);
  }

  i = 0;
  for (i = 0; i < MAX; i++) {
    printf("%d ", dequeue(queue));
  }

  printf("\n");

  return 0;
}