//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
  int *array;
  int front;
  int rear;
  int size;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->array = (int *)malloc(sizeof(int) * size);
  queue->front = -1;
  queue->rear = -1;
  queue->size = size;
  return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
  return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue *queue) {
  return queue->rear == queue->size - 1;
}

// Add an element to the queue
void enqueue(Queue *queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
    return;
  }

  // If the queue is empty, initialize the front and rear pointers
  if (isEmpty(queue)) {
    queue->front = 0;
    queue->rear = 0;
  } else {
    // Increment the rear pointer
    queue->rear++;
  }

  // Insert the data into the queue
  queue->array[queue->rear] = data;
}

// Remove an element from the queue
int dequeue(Queue *queue) {
  int data;

  // Check if the queue is empty
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }

  // If the queue has only one element, reset the front and rear pointers
  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    // Increment the front pointer
    queue->front++;
  }

  // Retrieve the data from the queue
  data = queue->array[queue->front];
  return data;
}

// Print the queue
void printQueue(Queue *queue) {
  int i;

  // Check if the queue is empty
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return;
  }

  // Print the elements of the queue
  printf("Queue: ");
  for (i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->array[i]);
  }
  printf("\n");
}

// Driver program to test the queue implementation
int main() {
  // Create a new queue
  Queue *queue = createQueue(5);

  // Add elements to the queue
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the queue
  printQueue(queue);

  // Remove elements from the queue
  dequeue(queue);
  dequeue(queue);

  // Print the queue
  printQueue(queue);

  // Add an element to the queue
  enqueue(queue, 6);

  // Print the queue
  printQueue(queue);

  return 0;
}