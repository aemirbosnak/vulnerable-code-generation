//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef struct {
  int items[QUEUE_SIZE];
  int front;
  int rear;
} Queue;

Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

int isEmpty(Queue *queue) {
  return queue->front == -1;
}

int isFull(Queue *queue) {
  return (queue->rear + 1) % QUEUE_SIZE == queue->front;
}

void enqueue(Queue *queue, int item) {
  if (isFull(queue)) {
    printf("Error: Queue is full!\n");
    return;
  }
  if (queue->front == -1) {
    queue->front = queue->rear = 0;
  } else {
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
  }
  queue->items[queue->rear] = item;
  printf("Enqueued: %d\n", item);
}

int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Error: Queue is empty!\n");
    return -1;
  }
  int item = queue->items[queue->front];
  if (queue->front == queue->rear) {
    queue->front = queue->rear = -1;
  } else {
    queue->front = (queue->front + 1) % QUEUE_SIZE;
  }
  printf("Dequeued: %d\n", item);
  return item;
}

void printQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return;
  }
  printf("Queue: ");
  int i = queue->front;
  while (i != queue->rear) {
    printf("%d ", queue->items[i]);
    i = (i + 1) % QUEUE_SIZE;
  }
  printf("%d\n", queue->items[i]);
}

int main() {
  Queue *queue = createQueue();
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  printQueue(queue);

  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  printQueue(queue);

  enqueue(queue, 6);
  enqueue(queue, 7);
  enqueue(queue, 8);

  printQueue(queue);

  return 0;
}