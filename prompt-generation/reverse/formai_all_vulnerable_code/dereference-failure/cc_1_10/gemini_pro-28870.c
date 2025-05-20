//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Initialize a queue
typedef struct Queue {
  int size;
  int front;
  int rear;
  int *items;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->size = size;
  queue->front = -1;
  queue->rear = -1;
  queue->items = (int *)malloc(size * sizeof(int));
  return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
  if (queue->rear == queue->size - 1) {
    return 1;
  }
  return 0;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
  if (queue->front == -1) {
    return 1;
  }
  return 0;
}

// Add an element to the queue
void enqueue(Queue *queue, int element) {
  if (isFull(queue)) {
    printf("Queue is full!\n");
  } else {
    if (queue->front == -1) {
      queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = element;
    printf("%d inserted to the queue\n", element);
  }
}

// Remove an element from the queue
int dequeue(Queue *queue) {
  int element;
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return (-1);
  } else {
    element = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
      queue->front = queue->rear = -1;
    }
    printf("%d deleted from the queue\n", element);
    return (element);
  }
}

// Print the queue
void display(Queue *queue) {
  int i;
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue: ");
    for (i = queue->front; i <= queue->rear; i++) {
      printf("%d ", queue->items[i]);
    }
    printf("\n");
  }
}

// Get the size of the queue
int size(Queue *queue) {
  return queue->rear - queue->front + 1;
}

// Drive code
int main() {
  // Create a queue of size 5
  Queue *queue = createQueue(5);

  // Enqueue elements
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  // Dequeue elements
  dequeue(queue);
  dequeue(queue);

  // Display the queue
  display(queue);

  // Get the size of the queue
  printf("Size of the queue: %d\n", size(queue));

  return 0;
}