//FormAI DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

struct queue {
  int items[MAXSIZE];
  int front;
  int rear;
};

typedef struct queue Queue;

void enqueue(Queue *q, int element) {
  if(q->rear == MAXSIZE-1) {
    printf("Queue is full\n");
  } else {
    if(q->front == -1) {
      q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = element;
    printf("Enqueued element: %d\n", element);
  }
}

int dequeue(Queue *q) {
  int element;
  if(q->front == -1 || q->front > q->rear) {
    printf("Queue is empty\n");
    return -1;
  } else {
    element = q->items[q->front];
    q->front++;
    printf("Dequeued element: %d\n", element);
    return element;
  }
}

void display(Queue *q) {
  int i;
  if(q->front == -1) {
    printf("Queue is empty\n");
  } else {
    printf("\nFront index: %d\n",q->front);
    printf("Items: ");
    for(i=q->front; i<=q->rear; i++) {
      printf("%d ",q->items[i]);
    }
    printf("\nRear index: %d\n",q->rear);
  }
}

int main() {
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->front = -1;
  q->rear = -1;

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);

  display(q);

  dequeue(q);
  dequeue(q);

  display(q);

  enqueue(q, 4);
  enqueue(q, 5);

  display(q);

  return 0;
}