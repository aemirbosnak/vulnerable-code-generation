//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct Node {
  int data;
  struct Node *next;
};

// Define the structure of a queue
struct Queue {
  struct Node *front;
  struct Node *rear;
};

// Create a new queue
struct Queue* createQueue() {
  struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Enqueue an element into the queue
void enqueue(struct Queue *queue, int data) {
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (queue->rear == NULL) {
    queue->front = newNode;
    queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
  if (queue->front == NULL) {
    printf("The queue is empty\n");
    return -1;
  }

  int data = queue->front->data;
  struct Node *temp = queue->front;
  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }
  free(temp);
  return data;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
  return queue->front == NULL;
}

// Print the elements of the queue
void printQueue(struct Queue *queue) {
  struct Node *temp = queue->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  struct Queue *queue = createQueue();
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  printQueue(queue);

  dequeue(queue);
  dequeue(queue);

  printQueue(queue);

  if (isEmpty(queue)) {
    printf("The queue is empty\n");
  } else {
    printf("The queue is not empty\n");
  }

  return 0;
}