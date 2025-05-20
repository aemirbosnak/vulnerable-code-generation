//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Define the Queue structure
typedef struct Queue {
  Node *front;
  Node *rear;
} Queue;

// Create a new queue
Queue* createQueue() {
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
  return (queue->front == NULL);
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int data) {
  Node *newNode = (Node*)malloc(sizeof(Node));
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
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  } else {
    int data = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
  }
}

// Print the queue
void printQueue(Queue *queue) {
  Node *temp = queue->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  Queue *queue = createQueue();
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  printQueue(queue); // Output: 1 2 3
  printf("Dequeued: %d\n", dequeue(queue)); // Output: 1
  printQueue(queue); // Output: 2 3
  enqueue(queue, 4);
  printQueue(queue); // Output: 2 3 4
  return 0;
}