//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 10

// Define the structure of a queue node
typedef struct QueueNode {
  int data;
  struct QueueNode *next;
} QueueNode;

// Define the structure of a queue
typedef struct Queue {
  QueueNode *front;
  QueueNode *rear;
  int size;
} Queue;

// Create a new queue
Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = NULL;
  queue->rear = NULL;
  queue->size = 0;
  return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
  return queue->size == 0;
}

// Check if the queue is full
int isFull(Queue *queue) {
  return queue->size == MAX_SIZE;
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full. Cannot enqueue.\n");
    return;
  }

  // Create a new node
  QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
  newNode->data = data;
  newNode->next = NULL;

  // If the queue is empty, set the front and rear to the new node
  if (isEmpty(queue)) {
    queue->front = newNode;
    queue->rear = newNode;
  } else {
    // Add the new node to the rear of the queue
    queue->rear->next = newNode;
    queue->rear = newNode;
  }

  // Increase the size of the queue
  queue->size++;
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1;
  }

  // Get the front element
  int data = queue->front->data;

  // If the queue has only one element, set the front and rear to NULL
  if (queue->size == 1) {
    queue->front = NULL;
    queue->rear = NULL;
  } else {
    // Move the front pointer to the next node
    queue->front = queue->front->next;
  }

  // Decrease the size of the queue
  queue->size--;

  return data;
}

// Print the elements of the queue
void printQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return;
  }

  // Traverse the queue and print the elements
  QueueNode *temp = queue->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

int main() {
  // Create a queue
  Queue *queue = createQueue();

  // Enqueue some elements into the queue
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the elements of the queue
  printf("Elements of the queue: ");
  printQueue(queue);

  // Dequeue some elements from the queue
  int data = dequeue(queue);
  printf("Dequeued element: %d\n", data);
  data = dequeue(queue);
  printf("Dequeued element: %d\n", data);

  // Print the elements of the queue
  printf("Elements of the queue: ");
  printQueue(queue);

  return 0;
}