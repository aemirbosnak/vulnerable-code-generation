//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 10

// Define the structure of a queue node
typedef struct queue_node {
  int data;
  struct queue_node *next;
} queue_node;

// Define the structure of a queue
typedef struct queue {
  queue_node *front;
  queue_node *rear;
  int size;
} queue;

// Create a new queue
queue *create_queue() {
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
  return q;
}

// Check if the queue is empty
int is_empty(queue *q) {
  return q->size == 0;
}

// Get the size of the queue
int get_size(queue *q) {
  return q->size;
}

// Enqueue an element into the queue
void enqueue(queue *q, int data) {
  // Create a new queue node
  queue_node *new_node = (queue_node *)malloc(sizeof(queue_node));
  new_node->data = data;
  new_node->next = NULL;

  // If the queue is empty, set both the front and rear to the new node
  if (is_empty(q)) {
    q->front = new_node;
    q->rear = new_node;
  } else {
    // Otherwise, add the new node to the end of the queue
    q->rear->next = new_node;
    q->rear = new_node;
  }

  // Increment the size of the queue
  q->size++;
}

// Dequeue an element from the queue
int dequeue(queue *q) {
  // If the queue is empty, return -1
  if (is_empty(q)) {
    return -1;
  }

  // Get the data from the front of the queue
  int data = q->front->data;

  // Move the front of the queue to the next node
  q->front = q->front->next;

  // If the queue is now empty, set both the front and rear to NULL
  if (is_empty(q)) {
    q->front = NULL;
    q->rear = NULL;
  }

  // Decrement the size of the queue
  q->size--;

  // Return the data from the front of the queue
  return data;
}

// Print the queue
void print_queue(queue *q) {
  // If the queue is empty, print "Empty queue"
  if (is_empty(q)) {
    printf("Empty queue\n");
    return;
  }

  // Otherwise, print the data from each node in the queue
  queue_node *curr = q->front;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

// Main function
int main() {
  // Create a new queue
  queue *q = create_queue();

  // Enqueue some elements into the queue
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);

  // Print the queue
  printf("Queue: ");
  print_queue(q);

  // Dequeue some elements from the queue
  printf("Dequeued element: %d\n", dequeue(q));
  printf("Dequeued element: %d\n", dequeue(q));

  // Print the queue
  printf("Queue: ");
  print_queue(q);

  // Enqueue some more elements into the queue
  enqueue(q, 6);
  enqueue(q, 7);

  // Print the queue
  printf("Queue: ");
  print_queue(q);

  // Get the size of the queue
  printf("Size of the queue: %d\n", get_size(q));

  // Dequeue all the remaining elements from the queue
  while (!is_empty(q)) {
    printf("Dequeued element: %d\n", dequeue(q));
  }

  // Print the queue
  printf("Queue: ");
  print_queue(q);

  return 0;
}