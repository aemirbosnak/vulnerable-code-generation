//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int *data;
  int head;
  int tail;
  int size;
} queue_t;

queue_t *queue_create(int size) {
  queue_t *queue = malloc(sizeof(queue_t));
  queue->data = malloc(size * sizeof(int));
  queue->head = 0;
  queue->tail = 0;
  queue->size = size;
  return queue;
}

void queue_destroy(queue_t *queue) {
  free(queue->data);
  free(queue);
}

int queue_is_empty(queue_t *queue) {
  return queue->head == queue->tail;
}

int queue_is_full(queue_t *queue) {
  return (queue->tail + 1) % queue->size == queue->head;
}

void queue_enqueue(queue_t *queue, int value) {
  if (queue_is_full(queue)) {
    fprintf(stderr, "Queue is full\n");
    return;
  }
  queue->data[queue->tail] = value;
  queue->tail = (queue->tail + 1) % queue->size;
}

int queue_dequeue(queue_t *queue) {
  if (queue_is_empty(queue)) {
    fprintf(stderr, "Queue is empty\n");
    return -1;
  }
  int value = queue->data[queue->head];
  queue->head = (queue->head + 1) % queue->size;
  return value;
}

int main() {
  queue_t *queue = queue_create(10);
  for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, i);
  }
  while (!queue_is_empty(queue)) {
    printf("%d\n", queue_dequeue(queue));
  }
  queue_destroy(queue);
  return 0;
}