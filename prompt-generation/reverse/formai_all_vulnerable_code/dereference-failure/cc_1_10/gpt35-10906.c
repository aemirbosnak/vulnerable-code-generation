//FormAI DATASET v1.0 Category: Queue ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct {
  int items[MAX_QUEUE_SIZE];
  int front, rear;
} Queue;

void initQueue(Queue *q) {
  q->front = -1;
  q->rear = -1;
}

int isFull(Queue *q) {
  if(q->rear == MAX_QUEUE_SIZE - 1) return 1;
  return 0;
}

int isEmpty(Queue *q) {
  if(q->front == -1) return 1;
  return 0;
}

void enQueue(Queue *q, int value) {
  if(isFull(q)) {
    printf("The queue is full. Cannot insert %d\n", value);
    return;
  }
  if(q->front == -1) q->front = 0;
  q->rear++;
  q->items[q->rear] = value;
}

int deQueue(Queue *q) {
  int item;
  if(isEmpty(q)) {
    printf("The queue is empty. Cannot delete item.\n");
    return -1;
  }
  item = q->items[q->front];
  q->front++;
  if(q->front > q->rear) {
    q->front = -1;
    q->rear = -1;
  }
  return item;
}

void main() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  initQueue(q);
  enQueue(q, 5);
  enQueue(q, 10);
  enQueue(q, 15);
  enQueue(q, 20);
  enQueue(q, 25);
  enQueue(q, 30); // this shouldn't work because queue is full
  printf("Deleted Item: %d\n", deQueue(q));
  printf("Deleted Item: %d\n", deQueue(q));
  printf("Deleted Item: %d\n", deQueue(q));
  printf("Deleted Item: %d\n", deQueue(q));
  printf("Deleted Item: %d\n", deQueue(q));
  printf("Deleted Item: %d\n", deQueue(q)); // this shouldn't work because queue is empty
}