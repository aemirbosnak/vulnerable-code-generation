//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
  int front, rear, capacity;
  int *array;
} Queue;

// Function to create a Queue of given capacity
Queue* createQueue(int capacity) {
  Queue* queue = (Queue*) malloc(sizeof(Queue));
  queue->front = queue->rear = -1;
  queue->capacity = capacity;
  queue->array = (int*) malloc(queue->capacity * sizeof(int));
  return queue;
}

// Function to check if the Queue is full
int isFull(Queue* queue) {
  return (queue->rear == queue->capacity - 1);
}

// Function to check if the Queue is empty
int isEmpty(Queue* queue) {
  return (queue->front == -1);
}

// Function to add an element to the Queue
void enqueue(Queue* queue, int item) {
  if (isFull(queue)) {
    printf("Queue is full, cannot add item.\n");
    return;
  }
  if (queue->front == -1) {
    queue->front = 0;
  }
  queue->rear++;
  queue->array[queue->rear] = item;
  printf("%d added to the queue.\n", item);
}

// Function to remove an element from the Queue
int dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty, cannot remove item.\n");
    return -1;
  }
  int item = queue->array[queue->front];
  queue->front++;
  if (queue->front > queue->rear) {
    queue->front = queue->rear = -1;
  }
  printf("%d removed from the queue.\n", item);
  return item;
}

// Function to print the Queue
void printQueue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return;
  }
  printf("Queue: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->array[i]);
  }
  printf("\n");
}

// Driver code to test the Queue
int main() {
  // Create a Queue of capacity 5
  Queue* queue = createQueue(5);

  // Enqueue elements to the Queue
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the Queue
  printQueue(queue);

  // Dequeue elements from the Queue
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  // Print the Queue
  printQueue(queue);

  // Add element to the Queue
  enqueue(queue, 6);

  // Print the Queue
  printQueue(queue);

  return 0;
}