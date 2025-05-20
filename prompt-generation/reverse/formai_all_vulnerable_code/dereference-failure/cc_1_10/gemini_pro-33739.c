//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
  int data;
  struct node *next;
};

// Define the queue structure
struct queue {
  struct node *front; // Front of the queue
  struct node *rear;  // Rear of the queue
};

// Create a new queue
struct queue *create_queue() {
  struct queue *q = (struct queue *)malloc(sizeof(struct queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

// Check if the queue is empty
int is_empty(struct queue *q) {
  return q->front == NULL;
}

// Add an element to the queue
void enqueue(struct queue *q, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if (is_empty(q)) {
    q->front = q->rear = new_node;
  } else {
    q->rear->next = new_node;
    q->rear = new_node;
  }
}

// Remove an element from the queue
int dequeue(struct queue *q) {
  if (is_empty(q)) {
    printf("Error: Queue is empty.\n");
    return -1;
  }

  int data = q->front->data;
  struct node *temp = q->front;
  q->front = q->front->next;
  if (q->front == NULL) {
    q->rear = NULL;
  }
  free(temp);
  return data;
}

// Get the front element of the queue
int front(struct queue *q) {
  if (is_empty(q)) {
    printf("Error: Queue is empty.\n");
    return -1;
  }
  return q->front->data;
}

// Print the queue
void print_queue(struct queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty.\n");
    return;
  }

  struct node *temp = q->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Driver code
int main() {
  // Create a queue
  struct queue *q = create_queue();

  // Add elements to the queue
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);

  // Print the queue
  printf("Queue: ");
  print_queue(q);

  // Remove an element from the queue
  int data = dequeue(q);
  printf("Removed element: %d\n", data);

  // Get the front element of the queue
  int front_element = front(q);
  printf("Front element: %d\n", front_element);

  // Print the queue
  printf("Queue: ");
  print_queue(q);

  return 0;
}