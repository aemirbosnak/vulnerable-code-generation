//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: minimalist
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
  int size;
  int capacity;
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

  queue->size++;
  if (queue->size == queue->capacity) {
    printf("Queue Overflow\n");
  }
}

int dequeue(struct Queue* queue) {
  if (queue->size == 0) {
    printf("Queue Underflow\n");
    return -1;
  }

  int data = queue->head->data;
  queue->head = queue->head->next;
  queue->size--;

  return data;
}

int main() {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  queue->capacity = MAX;

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  int data = dequeue(queue);
  printf("Data: %d\n", data);

  data = dequeue(queue);
  printf("Data: %d\n", data);

  data = dequeue(queue);
  printf("Data: %d\n", data);

  return 0;
}