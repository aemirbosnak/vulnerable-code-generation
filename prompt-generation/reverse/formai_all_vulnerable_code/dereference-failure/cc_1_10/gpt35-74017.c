//FormAI DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
  int front;
  int rear;
  int items[MAX_SIZE];
} Queue;

Queue* createQueue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

int isEmpty(Queue* queue) {
  return queue->front == -1;
}

int isFull(Queue* queue) {
  return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue* queue, int item) {
  if (isFull(queue)) {
    printf("Queue is full\n");
    return;
  }
  if (queue->front == -1) {
    queue->front = 0;
  }
  queue->rear++;
  queue->items[queue->rear] = item;
  printf("Enqueued: %d\n", item);
}

int dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return -1;
  }
  int item = queue->items[queue->front];
  queue->front++;
  if (queue->front > queue->rear) {
    queue->front = queue->rear = -1;
  }
  printf("Dequeued: %d\n", item);
  return item;
}

void printQueue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->items[i]);
  }
  printf("\n");
}

int main() {
  Queue* queue = createQueue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);

  printQueue(queue);

  dequeue(queue);
  dequeue(queue);

  printQueue(queue);

  enqueue(queue, 4);
  enqueue(queue, 5);

  printQueue(queue);

  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  printQueue(queue);

  return 0;
}