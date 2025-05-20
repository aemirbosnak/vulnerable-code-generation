//FormAI DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct queue {
  int* items;
  int front;
  int rear;
} queue;

queue* create_queue() {
  queue* q = malloc(sizeof(queue));
  q->items = malloc(MAX_QUEUE_SIZE * sizeof(int));
  q->front = -1;
  q->rear = -1;
  return q;
}

void enqueue(queue* q, int item) {
  if (q->rear == MAX_QUEUE_SIZE - 1) {
    printf("Queue overflow!\n");
    return;
  }
  if (q->front == -1 && q->rear == -1) {
    q->front = 0;
    q->rear = 0;
  } else {
    q->rear++;
  }
  q->items[q->rear] = item;
  printf("Enqueued %d to the queue\n", item);
}

int dequeue(queue* q) {
  if (q->front == -1) {
    printf("Queue underflow!\n");
    return -1;
  }
  int item = q->items[q->front];
  if (q->front == q->rear) {
    q->front = -1;
    q->rear = -1;
  } else {
    q->front++;
  }
  printf("Dequeued %d from the queue\n", item);
  return item;
}

void display(queue* q) {
  if (q->front == -1 && q->rear == -1) {
    printf("Queue is empty!\n");
    return;
  }
  printf("Queue: ");
  for (int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->items[i]);
  }
  printf("\n");
}

int main() {
  queue* q = create_queue();
  
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  enqueue(q, 6); // Queue overflow
  
  display(q); // Queue: 1 2 3 4 5
  
  dequeue(q);
  dequeue(q);
  
  display(q); // Queue: 3 4 5
  
  enqueue(q, 6);
  
  display(q); // Queue: 3 4 5 6
  
  return 0;
}