//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Struct representing the queue
struct Queue {
  int front, rear, size;
  unsigned capacity;
  int* array;
};

// Create a Queue with fixed Capacity
struct Queue* createQueue(unsigned capacity) {
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0; 
  queue->rear = capacity - 1; 
  queue->array = (int*) malloc(queue->capacity * sizeof(int));
  return queue;
}

// Queue is full when size is equal to the capacity
int isFull(struct Queue* queue) {
  return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
  return (queue->size == 0);
}

// Add an item to the Queue
void enqueue(struct Queue* queue, int item) {
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
  printf("%d enqueued to queue\n", item);
}

// Remove item from Queue
int dequeue(struct Queue* queue) {
  if (isEmpty(queue))
    return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}

// Get front item from Queue
int front(struct Queue* queue) {
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->front];
}

// Get rear item from Queue
int rear(struct Queue* queue) {
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->rear];
}

// Driver function
int main() {
  struct Queue* queue = createQueue(5);

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  printf("%d dequeued from queue\n\n", dequeue(queue));
  enqueue(queue, 4);
  enqueue(queue, 5);
  enqueue(queue, 6);
  printf("Front item is %d\n", front(queue));
  printf("Rear item is %d\n", rear(queue));
  printf("\n\n");

  return 0;
}