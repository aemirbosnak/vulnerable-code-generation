//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Queue struct
struct Queue {
  int front, rear, size;
  int *arr;
};

// Create a queue
struct Queue* createQueue(int size) {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = queue->rear = -1;
  queue->size = size;
  queue->arr = (int*)malloc(queue->size * sizeof(int));
  return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
  return queue->front == -1;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
  return (queue->rear + 1) % queue->size == queue->front;
}

// Enqueue an element
void enqueue(struct Queue* queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
    return;
  }
  
  // If the queue is empty, set the front to 0
  if (queue->front == -1) {
    queue->front = 0;
  }
  
  // Increment the rear and add the data
  queue->rear = (queue->rear + 1) % queue->size;
  queue->arr[queue->rear] = data;
}

// Dequeue an element
int dequeue(struct Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }
  
  // Get the front element and increment the front
  int data = queue->arr[queue->front];
  queue->front = (queue->front + 1) % queue->size;
  
  // If the queue is empty, set the front and rear to -1
  if (queue->front == -1) {
    queue->rear = -1;
  }
  
  return data;
}

// Print the queue
void printQueue(struct Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return;
  }
  
  int i = queue->front;
  while (i != queue->rear) {
    printf("%d ", queue->arr[i]);
    i = (i + 1) % queue->size;
  }
  printf("%d\n", queue->arr[i]);
}

// Driver code
int main() {
  // Create a queue of size 5
  struct Queue* queue = createQueue(5);
  
  // Enqueue some elements
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);
  
  // Print the queue
  printf("Queue: ");
  printQueue(queue);
  
  // Dequeue some elements
  dequeue(queue);
  dequeue(queue);
  
  // Print the queue
  printf("Queue after dequeue: ");
  printQueue(queue);
  
  // Enqueue some more elements
  enqueue(queue, 6);
  enqueue(queue, 7);
  
  // Print the queue
  printf("Queue after enqueue: ");
  printQueue(queue);
  
  return 0;
}