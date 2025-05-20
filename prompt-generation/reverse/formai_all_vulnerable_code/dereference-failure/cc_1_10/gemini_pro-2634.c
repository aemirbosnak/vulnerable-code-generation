//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

struct Queue {
  int items[QUEUE_SIZE];
  int front;
  int rear;
};

struct Queue* createQueue() {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

int isEmpty(struct Queue* queue) {
  return queue->front == -1;
}

void enqueue(struct Queue* queue, int item) {
  if (queue->rear == QUEUE_SIZE - 1) {
    printf("Queue is full.\n");
    return;
  }
  else if (isEmpty(queue)) {
    queue->front = queue->rear = 0;
  }
  else {
    queue->rear++;
  }
  queue->items[queue->rear] = item;
}

int dequeue(struct Queue* queue) {
  int item;
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return(-1);
  }
  else if (queue->front == queue->rear) {
    item = queue->items[queue->front];
    queue->front = queue->rear = -1;
  }
  else {
    item = queue->items[queue->front];
    queue->front++;
  }
  return(item);
}

void display(struct Queue* queue) {
  int i;
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return;
  }
  else {
    printf("Queue elements:\n");
    for (i = queue->front; i <= queue->rear; i++) {
      printf("%d  ", queue->items[i]);
    }
    printf("\n");
  }
}

int main() {
  struct Queue* queue = createQueue();

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  display(queue);

  printf("%d dequeued from queue.\n", dequeue(queue));
  printf("%d dequeued from queue.\n", dequeue(queue));

  display(queue);

  enqueue(queue, 60);
  enqueue(queue, 70);

  display(queue);

  printf("%d dequeued from queue.\n", dequeue(queue));
  printf("%d dequeued from queue.\n", dequeue(queue));
  printf("%d dequeued from queue.\n", dequeue(queue));
  printf("%d dequeued from queue.\n", dequeue(queue));

  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
  }
  else {
    printf("Queue is not empty.\n");
  }

  return 0;
}