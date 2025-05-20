//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int *arr;
  int head;
  int tail;
  int size;
} Queue;

Queue *createQueue(int size) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->arr = (int *)malloc(size * sizeof(int));
  queue->head = -1;
  queue->tail = -1;
  queue->size = size;
  return queue;
}

void enqueue(Queue *queue, int data) {
  if ((queue->tail + 1) % queue->size == queue->head) {
    printf("Queue is full!");
    return;
  } else if (queue->head == -1 && queue->tail == -1) {
    queue->head = 0;
    queue->tail = 0;
    queue->arr[queue->tail] = data;
  } else {
    queue->tail = (queue->tail + 1) % queue->size;
    queue->arr[queue->tail] = data;
  }
}

int dequeue(Queue *queue) {
  if (queue->head == -1 && queue->tail == -1) {
    printf("Queue is empty!");
    return -1;
  } else if (queue->head == queue->tail) {
    int data = queue->arr[queue->head];
    queue->head = -1;
    queue->tail = -1;
    return data;
  } else {
    int data = queue->arr[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return data;
  }
}

void display(Queue *queue) {
  if (queue->head == -1 && queue->tail == -1) {
    printf("Queue is empty!");
  } else {
    int i = queue->head;
    while (i != queue->tail) {
      printf("%d ", queue->arr[i]);
      i = (i + 1) % queue->size;
    }
    printf("%d ", queue->arr[queue->tail]);
  }
}

int main() {
  Queue *queue = createQueue(5);

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  display(queue);

  printf("\nDequeued: %d", dequeue(queue));
  printf("\nDequeued: %d", dequeue(queue));
  printf("\nDequeued: %d", dequeue(queue));

  display(queue);

  enqueue(queue, 6);
  enqueue(queue, 7);

  display(queue);

  return 0;
}