//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the scav queue
typedef struct {
  int size;
  int front;
  int rear;
  char **items;
} ScavQueue;

// Create a new scav queue
ScavQueue *createScavQueue(int size) {
  ScavQueue *queue = (ScavQueue *)malloc(sizeof(ScavQueue));
  queue->size = size;
  queue->front = -1;
  queue->rear = -1;
  queue->items = (char **)malloc(sizeof(char *) * size);
  return queue;
}

// Check if the scav queue is empty
int isEmptyScavQueue(ScavQueue *queue) {
  return queue->front == -1;
}

// Check if the scav queue is full
int isFullScavQueue(ScavQueue *queue) {
  return (queue->rear + 1) % queue->size == queue->front;
}

// Enqueue an item into the scav queue
void enqueueScavQueue(ScavQueue *queue, char *item) {
  if (isFullScavQueue(queue)) {
    printf("The scav queue is full!\n");
    return;
  }

  if (queue->front == -1) {
    queue->front = 0;
  }

  queue->rear = (queue->rear + 1) % queue->size;
  queue->items[queue->rear] = item;
}

// Dequeue an item from the scav queue
char *dequeueScavQueue(ScavQueue *queue) {
  if (isEmptyScavQueue(queue)) {
    printf("The scav queue is empty!\n");
    return NULL;
  }

  char *item = queue->items[queue->front];
  queue->front = (queue->front + 1) % queue->size;

  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  }

  return item;
}

// Destroy the scav queue
void destroyScavQueue(ScavQueue *queue) {
  free(queue->items);
  free(queue);
}

// Test the scav queue
int main() {
  ScavQueue *queue = createScavQueue(5);

  enqueueScavQueue(queue, "Food");
  enqueueScavQueue(queue, "Water");
  enqueueScavQueue(queue, "Medicine");
  enqueueScavQueue(queue, "Ammunition");
  enqueueScavQueue(queue, "Fuel");

  printf("The scav queue contains:\n");
  while (!isEmptyScavQueue(queue)) {
    printf("%s\n", dequeueScavQueue(queue));
  }

  destroyScavQueue(queue);

  return 0;
}