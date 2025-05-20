//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
struct Node {
  int data;
  struct Node *next;
};

// Define the structure of the queue
struct Queue {
  struct Node *front;
  struct Node *rear;
};

// Create a new queue
struct Queue *createQueue() {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
  return (queue->front == NULL);
}

// Enqueue an element into the queue
void enqueue(struct Queue *queue, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (isEmpty(queue)) {
    queue->front = newNode;
    queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("The queue is empty!\n");
    return -1;
  }

  struct Node *temp = queue->front;
  int data = temp->data;
  queue->front = temp->next;

  free(temp);

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  return data;
}

// Print the elements of the queue
void printQueue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("The queue is empty!\n");
    return;
  }

  struct Node *temp = queue->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  // Create a queue
  struct Queue *queue = createQueue();

  // Enqueue some elements into the queue
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the elements of the queue
  printf("The elements of the queue are: ");
  printQueue(queue);

  // Dequeue some elements from the queue
  printf("Dequeueing the front element: %d\n", dequeue(queue));
  printf("Dequeueing the next element: %d\n", dequeue(queue));

  // Print the elements of the queue
  printf("The elements of the queue after dequeuing two elements: ");
  printQueue(queue);

  return 0;
}