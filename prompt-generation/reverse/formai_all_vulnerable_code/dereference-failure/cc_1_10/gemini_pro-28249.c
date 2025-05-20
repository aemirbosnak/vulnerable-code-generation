//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// A node in the queue
struct Node {
  int data;
  struct Node *next;
};

// The queue
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
  return queue->front == NULL;
}

// Add an element to the queue
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

// Remove an element from the queue
int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  }

  struct Node *temp = queue->front;
  queue->front = queue->front->next;

  int data = temp->data;
  free(temp);

  return data;
}

// Get the size of the queue
int size(struct Queue *queue) {
  int count = 0;
  struct Node *temp = queue->front;

  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  return count;
}

// Print the queue
void printQueue(struct Queue *queue) {
  struct Node *temp = queue->front;

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

// Free the queue
void freeQueue(struct Queue *queue) {
  struct Node *temp;

  while (queue->front != NULL) {
    temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
  }

  free(queue);
}

int main() {
  struct Queue *queue = createQueue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  printQueue(queue);

  printf("Size of the queue: %d\n", size(queue));

  printf("Dequeue: %d\n", dequeue(queue));
  printf("Dequeue: %d\n", dequeue(queue));
  printf("Dequeue: %d\n", dequeue(queue));

  printQueue(queue);

  printf("Size of the queue: %d\n", size(queue));

  freeQueue(queue);

  return 0;
}