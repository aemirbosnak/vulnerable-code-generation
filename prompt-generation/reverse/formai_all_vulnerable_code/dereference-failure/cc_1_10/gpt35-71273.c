//FormAI DATASET v1.0 Category: Queue ; Style: brave
// Welcome to the Brave C Queue example!

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Create a structure to hold our queue
typedef struct Queue {
  int front, rear, size;
  unsigned int capacity;
  int *array;
} Queue;

// Initialize an empty queue of specified capacity
Queue *createQueue(unsigned int capacity) {
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;
  queue->array = (int*)malloc(queue->capacity * sizeof(int));
  return queue;
}

// Function to check if queue is full
int isFull(Queue *queue) {
  return (queue->size == queue->capacity);
}

// Function to check if queue is empty
int isEmpty(Queue *queue) {
  return (queue->size == 0);
}

// Function to add an item to the rear of the queue
void enqueue(Queue *queue, int item) {
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size++;
  printf("%d enqueued to queue\n", item);
  
}

// Function to remove an item from the front of the queue
int dequeue(Queue *queue) {
  if (isEmpty(queue))
    return -1; // Arbitrary value to represent an empty queue
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;
  return item;
}

// Driver function to test above functions
int main() {
  int capacity = 10;
  Queue *queue = createQueue(capacity);
  
  // Enqueue some items to the queue
  enqueue(queue, 5);
  enqueue(queue, 10);
  enqueue(queue, 15);
  
  // Dequeue the items and print them
  printf("%d dequeued from queue\n", dequeue(queue));
  printf("%d dequeued from queue\n", dequeue(queue));
  
  // Enqueue some more items and print them
  enqueue(queue, 20);
  printf("%d enqueued to queue\n", 20);
  enqueue(queue, 25);
  printf("%d enqueued to queue\n", 25);
  
  // Dequeue the remaining items and print them
  while (!isEmpty(queue)) {
    printf("%d dequeued from queue\n", dequeue(queue));
  }
  
  // Free up memory before exiting 
  free(queue->array);
  free(queue);
  return 0;
}