//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int front = -1, rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int num) {
  if (rear == MAX_QUEUE_SIZE - 1) {
    printf("Sorry, the queue is full!\n\n");
  } else {
    if (front == -1 && rear == -1) {
      front = rear = 0;
      queue[rear] = num;
    } else {
      rear++;
      queue[rear] = num;
    }
    printf("Successfully enqueued %d!\n\n", num);
  }
}

void dequeue() {
  if (front == -1 && rear == -1) {
    printf("Sorry, the queue is empty!\n\n");
  } else {
    int num = queue[front];
    if (front == rear) {
      front = rear = -1;
    } else {
      front++;
    }
    printf("Successfully dequeued %d!\n\n", num);
  }
}

int main() {
  printf("Welcome to the surreal queue implementation program!\n");
  printf("Unlike normal queues, this queue can only store surreal numbers!\n");
  printf("So, let's start by enqueueing some surreal numbers!\n\n");

  enqueue(42);
  enqueue(8675309);
  enqueue(3.14);
  enqueue(0.99999);
  enqueue(6/0);

  printf("Now, let's try dequeuing some surreal numbers!\n\n");

  dequeue(); // dequeues 42
  dequeue(); // dequeues 8675309
  dequeue(); // dequeues 3.14
  dequeue(); // dequeues 0.99999
  dequeue(); // dequeues 6/0

  printf("Wow, we just dequeued a surreal number! That was unexpected!\n");
  printf("But don't worry, this surreal queue implementation can handle anything!\n");

  return 0;
}