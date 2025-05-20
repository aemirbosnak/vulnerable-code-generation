//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct ParanoiaQueue {
  char **buffer;
  int front;
  int rear;
  int size;
  int is_locked;
} ParanoiaQueue;

ParanoiaQueue* paranoia_queue_init(int size) {
  ParanoiaQueue* queue = malloc(sizeof(ParanoiaQueue));
  queue->buffer = malloc(size * BUFFER_SIZE);
  queue->front = 0;
  queue->rear = -1;
  queue->size = size;
  queue->is_locked = 0;
  return queue;
}

void paranoia_queue_push(ParanoiaQueue* queue, char* data) {
  if (queue->is_locked) {
    return;
  }
  queue->is_locked = 1;
  queue->rear = (queue->rear + 1) % queue->size;
  queue->buffer[queue->rear] = data;
  queue->is_locked = 0;
}

char* paranoia_queue_pop(ParanoiaQueue* queue) {
  if (queue->is_locked) {
    return NULL;
  }
  queue->is_locked = 1;
  queue->front = (queue->front + 1) % queue->size;
  char* data = queue->buffer[queue->front];
  queue->is_locked = 0;
  return data;
}

int main() {
  ParanoiaQueue* queue = paranoia_queue_init(BUFFER_SIZE);
  paranoia_queue_push(queue, "a");
  paranoia_queue_push(queue, "b");
  paranoia_queue_push(queue, "c");
  paranoia_queue_push(queue, "d");

  char* data = paranoia_queue_pop(queue);
  printf("%s\n", data);

  data = paranoia_queue_pop(queue);
  printf("%s\n", data);

  return 0;
}