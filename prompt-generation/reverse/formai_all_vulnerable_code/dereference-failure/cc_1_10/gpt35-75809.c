//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Queue structure
struct Queue {
  int arr[MAX_SIZE];
  int front;
  int rear;
};

// Function to create a new queue
struct Queue* create_queue() {
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

// Function to enqueue a value to the queue
void enqueue(struct Queue* queue, int value) {
  if (queue->rear == MAX_SIZE - 1) {
    printf("\nQueue overflow! Cannot enqueue any further.\n");
    return;
  }

  if (queue->front == -1) {
    queue->front = 0;
  }
  queue->rear++;
  queue->arr[queue->rear] = value;
}

// Function to dequeue a value from the queue
int dequeue(struct Queue* queue) {
  if (queue->front == -1 || queue->front > queue->rear) {
    printf("\nQueue underflow! Cannot dequeue any further.\n");
    return -1;
  }

  int value = queue->arr[queue->front];
  queue->front++;
  return value;
}

// Function to print the elements of the queue
void display(struct Queue* queue) {
  if (queue->front == -1 || queue->front > queue->rear) {
    printf("\nQueue is empty!\n");
    return;
  }

  printf("\nQueue elements: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->arr[i]);
  }
  printf("\n");
}

// Main function to demonstrate how the queue works
int main() {
  struct Queue* queue = create_queue();

  enqueue(queue, 5);
  enqueue(queue, 10);
  enqueue(queue, 15);
  enqueue(queue, 20);
  display(queue);

  printf("Dequeued element: %d\n", dequeue(queue));
  display(queue);

  enqueue(queue, 25);
  enqueue(queue, 30);
  enqueue(queue, 35);
  enqueue(queue, 40);
  enqueue(queue, 45);
  display(queue);

  enqueue(queue, 50);

  return 0;
}