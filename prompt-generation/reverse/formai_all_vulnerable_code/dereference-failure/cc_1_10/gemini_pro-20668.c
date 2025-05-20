//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the Queue struct
typedef struct Queue {
  int *array;
  int head;
  int tail;
  int size;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->array = (int *)malloc(sizeof(int) * size);
  queue->head = 0;
  queue->tail = 0;
  queue->size = size;
  return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
  return queue->head == queue->tail;
}

// Check if the queue is full
int isFull(Queue *queue) {
  return (queue->tail + 1) % queue->size == queue->head;
}

// Enqueue an element
void enqueue(Queue *queue, int element) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
    return;
  }
  queue->array[queue->tail] = element;
  queue->tail = (queue->tail + 1) % queue->size;
}

// Dequeue an element
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }
  int element = queue->array[queue->head];
  queue->head = (queue->head + 1) % queue->size;
  return element;
}

// Print the queue
void printQueue(Queue *queue) {
  printf("Queue: ");
  for (int i = queue->head; i != queue->tail; i = (i + 1) % queue->size) {
    printf("%d ", queue->array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  // Create a queue of size 5
  Queue *queue = createQueue(5);

  // Enqueue some elements
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the queue
  printQueue(queue);

  // Dequeue some elements
  dequeue(queue);
  dequeue(queue);

  // Print the queue again
  printQueue(queue);

  // Enqueue some more elements
  enqueue(queue, 6);
  enqueue(queue, 7);

  // Print the queue one last time
  printQueue(queue);

  return 0;
}