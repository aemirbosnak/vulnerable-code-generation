//FormAI DATASET v1.0 Category: Queue ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct queue {
  int data[QUEUE_SIZE];
  int front, rear;
} Queue;

Queue *createQueue()
{
  Queue *q = (Queue*) malloc(sizeof(Queue));
  q->front = q->rear = -1;
  return q;
}

int isQueueEmpty(Queue *q)
{
  return (q->front == -1);
}

int isQueueFull(Queue *q)
{
  return ((q->rear + 1) % QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, int val)
{
  if (isQueueFull(q)) {
    printf("Queue overflow!\n");
    return;
  }

  if (isQueueEmpty(q)) {
    q->front = q->rear = 0;
    q->data[q->rear] = val;
  } else {
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = val;
  }

  printf("%d enqueued successfully!\n", val);
}

int dequeue(Queue *q)
{
  if (isQueueEmpty(q)) {
    printf("Queue underflow!\n");
    return -1;
  }

  int val = q->data[q->front];

  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % QUEUE_SIZE;
  }

  printf("%d dequeued successfully!\n", val);
  return val;
}

int main()
{
  Queue *q = createQueue();

  // Enqueue some values
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  printf("\n");

  // Dequeue some values
  dequeue(q);
  dequeue(q);
  printf("\n");

  // Enqueue some more values
  enqueue(q, 40);
  enqueue(q, 50);
  enqueue(q, 60);
  enqueue(q, 70);
  enqueue(q, 80);

  // Try to enqueue more values than queue capacity
  enqueue(q, 90);
  enqueue(q, 100);

  return 0;
}