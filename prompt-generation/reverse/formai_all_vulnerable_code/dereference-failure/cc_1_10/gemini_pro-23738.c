//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Queue structure
typedef struct Queue {
  int front, rear;
  int size;
  char **data;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = queue->rear = -1;
  queue->size = size;
  queue->data = (char **)malloc(queue->size * sizeof(char *));
  return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
  return (queue->rear == queue->size - 1);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
  return (queue->front == -1);
}

// Enqueue an element into the queue
void enqueue(Queue *queue, char *data) {
  if (isFull(queue)) {
    printf("Error: Queue is full!\n");
    return;
  }
  if (queue->front == -1) {
    queue->front = queue->rear = 0;
  } else {
    queue->rear++;
  }
  queue->data[queue->rear] = strdup(data);
}

// Dequeue an element from the queue
char *dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Error: Queue is empty!\n");
    return NULL;
  }
  char *data = queue->data[queue->front];
  if (queue->front == queue->rear) {
    queue->front = queue->rear = -1;
  } else {
    queue->front++;
  }
  return data;
}

// Print the queue
void printQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return;
  }
  printf("Queue: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%s  ", queue->data[i]);
  }
  printf("\n");
}

// Destroy the queue
void destroyQueue(Queue *queue) {
  for (int i = queue->front; i <= queue->rear; i++) {
    free(queue->data[i]);
  }
  free(queue->data);
  free(queue);
}

int main() {
  // Create a queue
  Queue *queue = createQueue(5);

  // Enqueue some elements into the queue
  enqueue(queue, "The moon is a harsh mistress");
  enqueue(queue, "The stars are cold and distant");
  enqueue(queue, "The sun is a fiery abyss");
  enqueue(queue, "The planets are a cosmic circus");

  // Print the queue
  printQueue(queue);

  // Dequeue some elements from the queue
  char *data1 = dequeue(queue);
  char *data2 = dequeue(queue);

  // Print the queue
  printQueue(queue);

  // Destroy the queue
  destroyQueue(queue);

  return 0;
}