//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

/* Create a structure for the queue */
struct Queue {
  int items[MAX_SIZE];
  int front;
  int rear;
};

/* Create functions for the queue */
struct Queue* createQueue() {
  struct Queue* q = malloc(sizeof(struct Queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

void enqueue(struct Queue* q, int value) {
  if (q->rear == MAX_SIZE - 1)
    printf("Queue is full.\n");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

int dequeue(struct Queue* q) {
  if (q->front == -1)
    printf("Queue is empty.\n");
  else {
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
    return item;
  }
}

void display(struct Queue* q) {
  if (q->rear == -1)
    printf("Queue is empty.\n");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = q->front; i <= q->rear; i++)
      printf("%d ", q->items[i]);
  }
}

int main() {
  struct Queue* q = createQueue();

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);

  display(q);

  printf("\nDequeued item: %d\n", dequeue(q));
  printf("Dequeued item: %d\n", dequeue(q));

  display(q);

  return 0;
}