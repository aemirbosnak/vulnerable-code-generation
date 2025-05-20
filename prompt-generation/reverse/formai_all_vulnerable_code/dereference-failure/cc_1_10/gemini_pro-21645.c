//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

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

int isEmpty(Queue* queue) {
  return queue->front == -1;
}

int isFull(Queue* queue) {
  return (queue->rear + 1) % QUEUE_SIZE == queue->front;
}

void enqueue(Queue* queue, int item) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
    return;
  }

  if (queue->front == -1) {
    queue->front = 0;
  }

  queue->rear = (queue->rear + 1) % QUEUE_SIZE;
  queue->items[queue->rear] = item;
}

int dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }

  int item = queue->items[queue->front];
  queue->front = (queue->front + 1) % QUEUE_SIZE;

  if (queue->front > queue->rear) {
    queue->front = queue->rear = -1;
  }

  return item;
}

int peek(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }

  return queue->items[queue->front];
}

void displayQueue(Queue* queue) {
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
  printf("%d\n", queue->items[queue->rear]);
}

int main() {
  Queue* queue = createQueue();

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  displayQueue(queue);

  printf("Dequeued element: %d\n", dequeue(queue));
  printf("Dequeued element: %d\n", dequeue(queue));
  printf("Dequeued element: %d\n", dequeue(queue));

  displayQueue(queue);

  enqueue(queue, 60);
  enqueue(queue, 70);

  displayQueue(queue);

  printf("Peek element: %d\n", peek(queue));

  enqueue(queue, 80);
  displayQueue(queue);

  return 0;
}