//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
  int data;
  struct Node *next;
};

// Queue structure
struct Queue {
  struct Node *front;
  struct Node *rear;
};

// Function to create a new queue
struct Queue *createQueue() {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
  return (queue->front == NULL);
}

// Function to add an element to the queue
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

// Function to remove an element from the queue
int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return -1;
  } else {
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
      queue->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
  }
}

// Function to get the front element of the queue without removing it
int peek(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return -1;
  } else {
    return queue->front->data;
  }
}

// Function to print the queue
void printQueue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
  } else {
    struct Node *temp = queue->front;
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

// Driver code
int main() {
  // Create a new queue
  struct Queue *queue = createQueue();

  // Enqueue some elements into the queue
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the queue
  printQueue(queue);

  // Dequeue some elements from the queue
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  // Print the queue
  printQueue(queue);

  // Get the front element of the queue
  int front = peek(queue);
  printf("Front element is: %d\n", front);

  return 0;
}