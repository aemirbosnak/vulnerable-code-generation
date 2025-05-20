//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct queue {
  struct node *front;
  struct node *rear;
} queue;

void enqueue(queue *q, int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;

  if (q->rear == NULL) {
    q->front = q->rear = temp;
  } else {
    q->rear->next = temp;
    q->rear = temp;
  }
}

int dequeue(queue *q) {
  if (q->front == NULL) {
    return -1;
  }

  int data = q->front->data;
  struct node *temp = q->front;
  q->front = q->front->next;

  free(temp);
  return data;
}

int main() {
  queue q;
  q.front = q.rear = NULL;

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);

  int data = dequeue(&q);
  printf("Dequeued data: %d\n", data);

  data = dequeue(&q);
  printf("Dequeued data: %d\n", data);

  data = dequeue(&q);
  printf("Dequeued data: %d\n", data);

  data = dequeue(&q);
  printf("Dequeued data: %d\n", data);

  data = dequeue(&q);
  printf("Dequeued data: %d\n", data);

  return 0;
}