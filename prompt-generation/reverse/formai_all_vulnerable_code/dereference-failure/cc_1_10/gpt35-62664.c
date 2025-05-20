//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Max number of elements the queue can hold

typedef struct {
  int data[MAX_SIZE];
  int head;
  int tail;
} Queue;

int is_full(Queue *q) {
  return q->tail == MAX_SIZE;
}

int is_empty(Queue *q) {
  return q->head == q->tail;
}

void enqueue(Queue *q, int value) {
  if (is_full(q)) {
    printf("Queue is full\n");
    return;
  }
  
  q->data[q->tail++] = value;
}

int dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return -1;
  }

  return q->data[q->head++];
}

void print_queue(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue: ");
  for (int i=q->head; i<q->tail; i++) {
    printf("%d ", q->data[i]);
  }
  printf("\n");
}

int main() {
  Queue *q = (Queue*) malloc(sizeof(Queue));
  q->head = 0;
  q->tail = 0;

  // Enqueue some values
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);

  // Print the queue
  print_queue(q);

  // Dequeue some values
  printf("Dequeued: %d\n", dequeue(q));
  printf("Dequeued: %d\n", dequeue(q));

  // Print the queue again
  print_queue(q);
  
  // Enqueue some more values
  enqueue(q, 40);
  enqueue(q, 50);

  // Print the queue once more
  print_queue(q);

  return 0;
}