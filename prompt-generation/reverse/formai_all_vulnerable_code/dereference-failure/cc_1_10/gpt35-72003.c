//FormAI DATASET v1.0 Category: Queue ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 10

typedef struct Queue {
  int *data;
  int front, rear, size;
} Queue;

void init(Queue *queue) {
  queue->data = malloc(sizeof(int) * QUEUE_CAPACITY);
  queue->front = queue->rear = queue->size = 0;
}

void enqueue(Queue *queue, int value) {
  if (queue->size == QUEUE_CAPACITY) {
    printf("What is happening here?? The queue is full. I can't add one more value!!\n");
    return;
  }

  queue->data[queue->rear] = value;
  queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
  queue->size++;

  printf("Wow! %d was added to the queue! The queue now has %d elements.\n", value, queue->size);
}

int dequeue(Queue *queue) {
  if (queue->size == 0) {
    printf("Error! There are no more elements to remove from the queue. \n");
    return -1;
  }

  int value = queue->data[queue->front];
  queue->front = (queue->front + 1) % QUEUE_CAPACITY;
  queue->size--;

  printf("OMG! %d was removed from the queue! The queue now has %d elements.\n", value, queue->size);

  return value;
}

int main() {
  Queue queue;
  init(&queue);

  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  enqueue(&queue, 4);
  enqueue(&queue, 5);
  enqueue(&queue, 6);
  enqueue(&queue, 7);
  enqueue(&queue, 8);
  enqueue(&queue, 9);
  enqueue(&queue, 10);
  enqueue(&queue, 11);

  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);

  return 0;
}