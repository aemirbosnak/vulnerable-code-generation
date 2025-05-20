//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct queue {
  int *elements;
  int head;
  int tail;
  int size;
};

struct queue *create_queue(int size) {
  struct queue *q = malloc(sizeof(struct queue));
  q->elements = malloc(sizeof(int) * size);
  q->head = 0;
  q->tail = 0;
  q->size = size;
  return q;
}

void enqueue(struct queue *q, int element) {
  if ((q->tail + 1) % q->size == q->head) {
    printf("Queue is full!\n");
    return;
  }
  q->elements[q->tail] = element;
  q->tail = (q->tail + 1) % q->size;
}

int dequeue(struct queue *q) {
  if (q->head == q->tail) {
    printf("Queue is empty!\n");
    return -1;
  }
  int element = q->elements[q->head];
  q->head = (q->head + 1) % q->size;
  return element;
}

int main() {
  struct queue *q = create_queue(5);
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  enqueue(q, 6);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  return 0;
}