//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
  int data;
  struct Node *next;
};

// Define the queue structure
struct Queue {
  struct Node *front, *rear;
};

// Create a new queue
struct Queue *createQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

// Check if the queue is empty
int isEmpty(struct Queue *q) {
  return (q->front == NULL);
}

// Enqueue an element to the queue
void enqueue(struct Queue *q, int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;

  if (q->rear == NULL) {
    q->front = q->rear = temp;
  } else {
    q->rear->next = temp;
    q->rear = temp;
  }
}

// Dequeue an element from the queue
int dequeue(struct Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }

  struct Node *temp = q->front;
  int data = temp->data;
  q->front = q->front->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }

  free(temp);
  return data;
}

// Print the queue
void printQueue(struct Queue *q) {
  struct Node *temp = q->front;

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

// Main function
int main() {
  // Create a queue
  struct Queue *q = createQueue();

  // Enqueue some elements
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);

  // Print the queue
  printf("Queue: ");
  printQueue(q);

  // Dequeue some elements
  printf("Dequeued: %d\n", dequeue(q));
  printf("Dequeued: %d\n", dequeue(q));

  // Print the queue
  printf("Queue: ");
  printQueue(q);

  return 0;
}