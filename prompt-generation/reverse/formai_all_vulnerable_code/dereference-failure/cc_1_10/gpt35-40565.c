//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

typedef struct queue queue;

void create_queue(queue *q) {
  q->front = -1;
  q->rear = -1;
}

int is_empty(queue *q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

int is_full(queue *q) {
  if (q->rear == SIZE - 1)
    return 1;
  else
    return 0;
}

void enqueue(queue *q, int value) {
  if (is_full(q))
    printf("Queue is full\n");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
  }
}

int dequeue(queue *q) {
  int item;
  if (is_empty(q)) {
    printf("Queue is empty\n");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Reset queue\n");
      q->front = q->rear = -1;
    }
  }
  return item;
}

void display(queue *q) {
  if (is_empty(q))
    printf("Queue is empty\n");
  else {
    int i;
    printf("Queue elements are:\n");
    for (i = q->front; i < q->rear + 1; i++)
      printf("%d\n", q->items[i]);
  }
}

int main() {
  queue *q = (queue *)malloc(sizeof(queue));
  create_queue(q);

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);

  display(q);

  dequeue(q);
  dequeue(q);

  display(q);

  enqueue(q, 5);
  enqueue(q, 6);

  display(q);

  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);

  display(q);

  enqueue(q, 7);
  enqueue(q, 8);

  display(q);

  dequeue(q);
  dequeue(q);

  display(q);

  return 0;
}