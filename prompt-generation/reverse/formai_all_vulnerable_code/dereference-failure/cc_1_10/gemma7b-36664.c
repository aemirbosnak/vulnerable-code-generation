//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Queue {
  Node* head;
  Node* tail;
  int size;
  int capacity;
};

void enqueue(struct Queue* queue, int data) {
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
  if (queue->size == queue->capacity) {
    queue->tail = queue->head;
  }
}

void dequeue(struct Queue* queue) {
  if (queue->head == NULL) {
    printf("Queue is empty\n");
    return;
  }

  Node* oldHead = queue->head;
  queue->head = oldHead->next;
  free(oldHead);

  queue->size--;
  if (queue->size == 0) {
    queue->tail = NULL;
  }
}

int main() {
  struct Queue* queue = malloc(sizeof(struct Queue));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  queue->capacity = MAX_SIZE;

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);

  dequeue(queue);
  dequeue(queue);

  enqueue(queue, 50);

  printf("Queue elements: ");
  for (Node* node = queue->head; node; node = node->next) {
    printf("%d ", node->data);
  }

  printf("\n");
  printf("Queue size: %d", queue->size);

  return 0;
}