//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
  char data[MAX_SIZE];
  struct Node* next;
} Node;

typedef struct Queue {
  Node* head;
  Node* tail;
  int size;
} Queue;

Queue* createQueue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

void enqueue(Queue* queue, char* data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->data, data);
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

char* dequeue(Queue* queue) {
  if (queue->size == 0) {
    return NULL;
  }

  char* data = queue->head->data;
  queue->head = queue->head->next;
  queue->size--;

  return data;
}

int main() {
  Queue* queue = createQueue();
  enqueue(queue, "John");
  enqueue(queue, "Mary");
  enqueue(queue, "Bob");

  char* name = dequeue(queue);
  printf("Dequeued name: %s\n", name);

  name = dequeue(queue);
  printf("Dequeued name: %s\n", name);

  name = dequeue(queue);
  printf("Dequeued name: %s\n", name);

  name = dequeue(queue);
  printf("Dequeued name: %s\n", name);

  return 0;
}