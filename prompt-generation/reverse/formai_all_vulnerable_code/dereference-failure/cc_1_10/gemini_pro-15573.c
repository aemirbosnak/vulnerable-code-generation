//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct Queue {
  int front;
  int rear;
  int size;
  int *arr;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = -1;
  q->rear = -1;
  q->size = size;
  q->arr = (int *)malloc(size * sizeof(int));
  return q;
}

// Check if the queue is full
int isFull(Queue *q) {
  return (q->rear == q->size - 1);
}

// Check if the queue is empty
int isEmpty(Queue *q) {
  return (q->front == -1);
}

// Enqueue an element
void enqueue(Queue *q, int data) {
  if (isFull(q)) {
    printf("Queue is full\n");
    return;
  }
  if (q->front == -1) {
    q->front = 0;
  }
  q->rear++;
  q->arr[q->rear] = data;
}

// Dequeue an element
int dequeue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  int data = q->arr[q->front];
  q->front++;
  if (q->front > q->rear) {
    q->front = q->rear = -1;
  }
  return data;
}

// Print the queue
void printQueue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return;
  }
  int i;
  for (i = q->front; i <= q->rear; i++) {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Create a queue of size 5
  Queue *q = createQueue(5);

  // Enqueue elements
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);

  // Print the queue
  printQueue(q);

  // Dequeue an element
  int data = dequeue(q);
  printf("Dequeued element: %d\n", data);

  // Print the queue
  printQueue(q);

  return 0;
}