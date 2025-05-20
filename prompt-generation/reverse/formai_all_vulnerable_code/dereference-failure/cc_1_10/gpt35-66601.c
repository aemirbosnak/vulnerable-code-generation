//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define max_size 5

// Struct for the Queue
struct queue {
  int items[max_size];
  int front;
  int rear;
};

// Creating a Queue
struct queue* newQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the Queue is empty
int isEmpty(struct queue* q) {
  if(q->rear == -1) 
    return 1;
  else 
    return 0;
}

// Check if the Queue is full
int isFull(struct queue* q) {
  if(q->rear == max_size-1)
    return 1;
  else
    return 0;
}

// Add items to the Queue
void enqueue(struct queue* q, int item) {
  if(isFull(q)) {
    printf("Queue is full.\n");
  } else {
    if(q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = item;
    printf("Inserted item: %d\n", item);
  }
}

// Remove items from the Queue
int dequeue(struct queue* q) {
  int item;
  if(isEmpty(q)) {
    printf("Queue is empty.\n");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if(q->front > q->rear) {
        printf("Resetting queue.\n");
        q->front = q->rear = -1;
    }
  }
  return item;
}

int main() {
  struct queue* q = newQueue();

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);

  printf("\nDequeuing items:\n");
  printf("%d ", dequeue(q));
  printf("%d ", dequeue(q));
  printf("\n");

  enqueue(q, 6);
  enqueue(q, 7);

  printf("\nDequeuing items:\n");
  printf("%d ", dequeue(q));
  printf("%d ", dequeue(q));
  printf("%d ", dequeue(q));
  printf("\n");

  enqueue(q, 8);

  return 0;
}