//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom queue implementation
typedef struct Queue {
  int front, rear, size;
  int *arr;
} Queue;

// Initialize queue
Queue *createQueue(int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->size = size;
  q->arr = (int *)malloc(size * sizeof(int));
  q->front = q->rear = -1;
  return q;
}

// Check if queue is empty
int isEmpty(Queue *q) {
  return q->front == -1;
}

// Check if queue is full
int isFull(Queue *q) {
  return q->rear == q->size - 1;
}

// Add element to queue
void enqueue(Queue *q, int data) {
  if (isFull(q)) {
    printf("Queue is full\n");
    return;
  }
  if (q->front == -1) {
    q->front = q->rear = 0;
  } else {
    q->rear++;
  }
  q->arr[q->rear] = data;
}

// Remove element from queue
int dequeue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  int data = q->arr[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front++;
  }
  return data;
}

// Get front element of queue
int front(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  return q->arr[q->front];
}

// Get rear element of queue
int rear(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  return q->arr[q->rear];
}

// Print queue
void printQueue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}

// Example usage
int main() {
  Queue *q = createQueue(5);
  printf("Is queue empty: %s\n", isEmpty(q) ? "Yes" : "No");
  printf("Enqueue 1, 2, 3, 4, 5\n");
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  printf("Is queue full: %s\n", isFull(q) ? "Yes" : "No");
  printf("Front element: %d\n", front(q));
  printf("Rear element: %d\n", rear(q));
  printf("Dequeue 3 elements\n");
  dequeue(q);
  dequeue(q);
  dequeue(q);
  printQueue(q);
  printf("Enqueue 6, 7\n");
  enqueue(q, 6);
  enqueue(q, 7);
  printQueue(q);
  printf("Dequeue all elements\n");
  while (!isEmpty(q)) {
    dequeue(q);
  }
  printf("Is queue empty: %s\n", isEmpty(q) ? "Yes" : "No");
  return 0;
}