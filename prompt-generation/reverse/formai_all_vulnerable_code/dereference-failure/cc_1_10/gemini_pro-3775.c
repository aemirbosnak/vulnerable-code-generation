//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
  int front, rear, size;
  int *array;
};

// Create a new queue
struct Queue* createQueue(int size) {
  struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = queue->rear = -1;
  queue->size = size;
  queue->array = (int*)malloc(queue->size * sizeof(int));
  return queue;
}

// Check if the queue is full
int isFull(struct Queue *queue) {
  return (queue->rear == queue->size - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
  return (queue->front == -1);
}

// Add an element to the queue
void enqueue(struct Queue *queue, int element) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
    return;
  }
  else {
    if (queue->front == -1) {
      queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = element;
    printf("%d inserted\n", element);
  }
}

// Remove an element from the queue
int dequeue(struct Queue *queue) {
  int element;
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return (-1);
  }
  else {
    element = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
      queue->front = queue->rear = -1;
    }
    printf("%d deleted\n", element);
    return (element);
  }
}

// Display the queue
void display(struct Queue *queue) {
  int i;
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
  }
  else {
    printf("Queue: ");
    for (i = queue->front; i <= queue->rear; i++) {
      printf("%d ", queue->array[i]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a queue of size 5
  struct Queue *queue = createQueue(5);

  // Enqueue elements
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  // Display the queue
  display(queue);

  // Dequeue elements
  dequeue(queue);
  dequeue(queue);

  // Display the queue
  display(queue);

  // Enqueue elements
  enqueue(queue, 60);
  enqueue(queue, 70);

  // Display the queue
  display(queue);

  // Dequeue elements
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  // Display the queue
  display(queue);

  return 0;
}