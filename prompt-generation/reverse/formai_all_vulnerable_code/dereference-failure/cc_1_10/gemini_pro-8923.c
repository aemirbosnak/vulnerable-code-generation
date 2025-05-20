//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 10

typedef struct Queue {
  int front, rear;
  int capacity;
  int *queue;
} Queue;

Queue *createQueue(int capacity) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = queue->rear = -1;
  queue->capacity = capacity;
  queue->queue = (int *)malloc(sizeof(int) * capacity);
  return queue;
}

int isFull(Queue *queue) { return (queue->rear == queue->capacity - 1); }

int isEmpty(Queue *queue) { return (queue->front == -1); }

void enqueue(Queue *queue, int item) {
  if (isFull(queue)) {
    printf("Queue is full\n");
    return;
  }
  if (queue->front == -1)
    queue->front = 0;
  queue->rear++;
  queue->queue[queue->rear] = item;
  printf("%d inserted into the queue\n", item);
}

int dequeue(Queue *queue) {
  int item;
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return (-1);
  }
  item = queue->queue[queue->front];
  queue->front++;
  if (queue->front > queue->rear)
    queue->front = queue->rear = -1;
  printf("%d deleted from the queue\n", item);
  return item;
}

void display(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements:\n");
  for (int i = queue->front; i <= queue->rear; i++)
    printf("%d ", queue->queue[i]);
  printf("\n");
}

void peek(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Front element: %d\n", queue->queue[queue->front]);
}

int main() {
  Queue *queue = createQueue(QUEUE_SIZE);
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  display(queue);
  peek(queue);
  dequeue(queue);
  enqueue(queue, 50);
  display(queue);
  peek(queue);
  dequeue(queue);
  display(queue);
  peek(queue);
  return 0;
}