//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct Queue {
  int items[QUEUE_SIZE];
  int front;
  int rear;
} Queue;

Queue* createQueue() {
  Queue* queue = (Queue*) malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

void enqueue(Queue* queue, int item) {
  if (queue->rear == QUEUE_SIZE - 1) {
    printf("Queue is full.\n");
    return;
  }

  if (queue->front == -1) {
    queue->front = 0;
  }

  queue->rear++;
  queue->items[queue->rear] = item;
}

int dequeue(Queue* queue) {
  if (queue->front == -1) {
    printf("Queue is empty.\n");
    return -1;
  }

  int item = queue->items[queue->front];
  queue->front++;

  if (queue->front > queue->rear) {
    queue->front = queue->rear = -1;
  }

  return item;
}

int isQueueEmpty(Queue* queue) {
  return queue->front == -1;
}

int isQueueFull(Queue* queue) {
  return queue->rear == QUEUE_SIZE - 1;
}

void printQueue(Queue* queue) {
  int i;
  if (isQueueEmpty(queue)) {
    printf("Queue is empty.\n");
    return;
  }

  printf("Queue: ");
  for (i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->items[i]);
  }
  printf("\n");
}

int main() {
  Queue* queue = createQueue();

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  printQueue(queue);

  dequeue(queue);
  dequeue(queue);

  printQueue(queue);

  enqueue(queue, 60);
  enqueue(queue, 70);

  printQueue(queue);

  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  printQueue(queue);

  return 0;
}