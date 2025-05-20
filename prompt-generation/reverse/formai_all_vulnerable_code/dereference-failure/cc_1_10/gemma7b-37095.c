//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Queue {
  Node* head;
  Node* tail;
  int size;
} Queue;

Queue* createQueue() {
  Queue* queue = malloc(sizeof(Queue));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

void enqueue(Queue* queue, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (queue->head == NULL) {
    queue->head = newNode;
    queue->tail = newNode;
  } else {
    queue->tail->next = newNode;
    queue->tail = newNode;
  }

  queue->size++;
}

int dequeue(Queue* queue) {
  if (queue->size == 0) {
    return -1;
  }

  int data = queue->head->data;
  queue->head = queue->head->next;
  queue->size--;

  return data;
}

int main() {
  Queue* queue = createQueue();

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);

  int data = dequeue(queue);

  if (data != -1) {
    printf("Data: %d\n", data);
  } else {
    printf("Queue is empty\n");
  }

  return 0;
}