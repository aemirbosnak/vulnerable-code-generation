//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Queue definition
typedef struct Queue {
  struct Node *front;
  struct Node *rear;
} Queue;

// Function to create a queue
Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
  return (queue->front == NULL);
}

// Function to enqueue an element
void enqueue(Queue *queue, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(Node));
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

// Function to dequeue an element
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1;
  } else {
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
  }
}

// Function to print the queue
void printQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. Nothing to print.\n");
  } else {
    struct Node *temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a queue
  Queue *queue = createQueue();

  // Enqueue some elements
  printf("Enqueuing elements...\n");
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the queue
  printf("Queue after enqueueing elements:\n");
  printQueue(queue);

  // Dequeue some elements
  printf("Dequeueing elements...\n");
  dequeue(queue);
  dequeue(queue);

  // Print the queue
  printf("Queue after dequeueing elements:\n");
  printQueue(queue);

  // Enqueue some more elements
  printf("Enqueuing more elements...\n");
  enqueue(queue, 6);
  enqueue(queue, 7);

  // Print the queue
  printf("Queue after enqueueing more elements:\n");
  printQueue(queue);

  // Dequeue all elements
  printf("Dequeueing all elements...\n");
  while (!isEmpty(queue)) {
    dequeue(queue);
  }

  // Print the queue
  printf("Queue after dequeueing all elements:\n");
  printQueue(queue);

  return 0;
}