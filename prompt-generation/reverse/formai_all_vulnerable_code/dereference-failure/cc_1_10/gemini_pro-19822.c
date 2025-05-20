//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define QUEUE_SIZE 100
#define MAX_RAND 100

struct Queue {
  int *arr;
  int capacity;
  int front;
  int rear;
  int size;
};

struct Queue *createQueue(int capacity) {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->arr = (int *)malloc(sizeof(int) * capacity);
  queue->front = 0;
  queue->rear = -1;
  queue->size = 0;
  return queue;
}

void enQueue(struct Queue *queue, int data) {
  if (queue->size == queue->capacity) {
    printf("Queue is full\n");
    return;
  }

  queue->rear++;
  if (queue->rear == queue->capacity) {
    queue->rear = 0;
  }

  queue->arr[queue->rear] = data;
  queue->size++;
}

int deQueue(struct Queue *queue) {
  if (queue->size == 0) {
    printf("Queue is empty\n");
    return -1;
  }

  int data = queue->arr[queue->front];
  queue->front++;
  if (queue->front == queue->capacity) {
    queue->front = 0;
  }

  queue->size--;
  return data;
}

int main() {
  struct Queue *queue = createQueue(QUEUE_SIZE);

  for (int i = 0; i < QUEUE_SIZE; i++) {
    int randNum = rand() % MAX_RAND + 1;
    enQueue(queue, randNum);
  }

  while (queue->size > 0) {
    printf("%d ", deQueue(queue));
  }

  printf("\n");

  return 0;
}