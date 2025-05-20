//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef struct Queue {
  int head;
  int tail;
  int size;
  int *items;
} Queue;

Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->head = 0;
  queue->tail = 0;
  queue->size = 0;
  queue->items = (int *)malloc(sizeof(int) * QUEUE_SIZE);
  return queue;
}

void destroyQueue(Queue *queue) {
  free(queue->items);
  free(queue);
}

int enqueue(Queue *queue, int item) {
  if (queue->size == QUEUE_SIZE) {
    return -1;
  }

  queue->items[queue->tail] = item;
  queue->tail = (queue->tail + 1) % QUEUE_SIZE;
  queue->size++;
  return 0;
}

int dequeue(Queue *queue) {
  if (queue->size == 0) {
    return -1;
  }

  int item = queue->items[queue->head];
  queue->head = (queue->head + 1) % QUEUE_SIZE;
  queue->size--;
  return item;
}

int main() {
  Queue *queue = createQueue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  printf("Queue: ");
  for (int i = 0; i < queue->size; i++) {
    printf("%d ", queue->items[(queue->head + i) % QUEUE_SIZE]);
  }
  printf("\n");

  dequeue(queue);
  dequeue(queue);

  printf("Queue after dequeue: ");
  for (int i = 0; i < queue->size; i++) {
    printf("%d ", queue->items[(queue->head + i) % QUEUE_SIZE]);
  }
  printf("\n");

  destroyQueue(queue);

  return 0;
}