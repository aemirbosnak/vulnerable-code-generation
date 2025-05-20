//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
  int data;
  struct node *next;
} node;

// Define the queue structure
typedef struct queue {
  node *front;
  node *rear;
} queue;

// Create a new queue
queue *createQueue() {
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

// Check if the queue is empty
int isEmpty(queue *q) {
  return q->front == NULL;
}

// Enqueue an element to the queue
void enqueue(queue *q, int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (isEmpty(q)) {
    q->front = new_node;
    q->rear = new_node;
  } else {
    q->rear->next = new_node;
    q->rear = new_node;
  }
}

// Dequeue an element from the queue
int dequeue(queue *q) {
  if (isEmpty(q)) {
    return -1;
  }

  int data = q->front->data;
  node *temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }

  free(temp);
  return data;
}

// Print the queue
void printQueue(queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return;
  }

  node *temp = q->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  queue *q = createQueue();

  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);

  printQueue(q);

  dequeue(q);
  dequeue(q);

  printQueue(q);

  enqueue(q, 50);
  enqueue(q, 60);

  printQueue(q);

  return 0;
}