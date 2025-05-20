//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *front, *rear;
  int size;
} Queue;

Queue *createQueue() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = q->rear = NULL;
  q->size = 0;
  return q;
}

void enqueue(Queue *q, int data) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;
  if (q->rear == NULL) {
    q->front = q->rear = temp;
  } else {
    q->rear->next = temp;
    q->rear = temp;
  }
  q->size++;
}

int dequeue(Queue *q) {
  if (q->front == NULL) {
    printf("Queue is empty!\n");
    return -1;
  }
  int data = q->front->data;
  Node *temp = q->front;
  q->front = q->front->next;
  free(temp);
  q->size--;
  return data;
}

int peek(Queue *q) {
  if (q->front == NULL) {
    printf("Queue is empty!\n");
    return -1;
  }
  return q->front->data;
}

int isEmpty(Queue *q) {
  return q->front == NULL;
}

void printQueue(Queue *q) {
  Node *temp = q->front;
  printf("[");
  while (temp != NULL) {
    printf("%d, ", temp->data);
    temp = temp->next;
  }
  printf("]\n");
}

int main() {
  Queue *q = createQueue();
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  printQueue(q);
  dequeue(q);
  dequeue(q);
  printQueue(q);
  printf("Peek: %d\n", peek(q));
  dequeue(q);
  dequeue(q);
  dequeue(q);
  printf("Is Empty: %d\n", isEmpty(q));
  return 0;
}