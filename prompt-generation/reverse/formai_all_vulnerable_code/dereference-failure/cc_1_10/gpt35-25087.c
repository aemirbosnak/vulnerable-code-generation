//FormAI DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* items;
  int max_size;
  int front;
  int rear;
  int size;
} Queue;

Queue* create_queue(int max_size) {
  Queue* q = (Queue*)malloc(sizeof(Queue));
  q->items = (int*)malloc(sizeof(int) * max_size);
  q->max_size = max_size;
  q->front = 0;
  q->rear = -1;
  q->size = 0;
  return q;
}

void enqueue(Queue* q, int val) {
  if (q->size == q->max_size) {
    printf("Queue is full");
    return;
  }
  q->rear = (q->rear + 1) % q->max_size;
  q->items[q->rear] = val;
  q->size++;
}

int dequeue(Queue* q) {
  if (q->size == 0) {
    printf("Queue is empty");
    return -1;
  }
  int val = q->items[q->front];
  q->front = (q->front + 1) % q->max_size;
  q->size--;
  return val;
}

int main() {
  Queue* q = create_queue(5);

  enqueue(q, 5);
  enqueue(q, 10);
  enqueue(q, 15);
  printf("Dequeue: %d\n", dequeue(q));
  enqueue(q, 20);
  printf("Dequeue: %d\n", dequeue(q));
  printf("Dequeue: %d\n", dequeue(q));
  printf("Dequeue: %d\n", dequeue(q));
  printf("Dequeue: %d\n", dequeue(q));
  
  return 0;
}