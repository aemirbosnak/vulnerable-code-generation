//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Define the queue structure
typedef struct queue {
  node_t *front;
  node_t *rear;
  int size;
} queue_t;

// Create a new queue
queue_t *create_queue() {
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  queue->front = NULL;
  queue->rear = NULL;
  queue->size = 0;
  return queue;
}

// Check if the queue is empty
int is_empty(queue_t *queue) {
  return queue->size == 0;
}

// Enqueue an element
void enqueue(queue_t *queue, int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  if (is_empty(queue)) {
    queue->front = new_node;
    queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }

  queue->size++;
}

// Dequeue an element
int dequeue(queue_t *queue) {
  if (is_empty(queue)) {
    return -1;
  }

  node_t *temp = queue->front;
  int data = temp->data;
  queue->front = temp->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  free(temp);
  queue->size--;

  return data;
}

// Get the front element
int front(queue_t *queue) {
  if (is_empty(queue)) {
    return -1;
  }

  return queue->front->data;
}

// Get the rear element
int rear(queue_t *queue) {
  if (is_empty(queue)) {
    return -1;
  }

  return queue->rear->data;
}

// Print the queue
void print_queue(queue_t *queue) {
  node_t *temp = queue->front;

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

// Destroy the queue
void destroy_queue(queue_t *queue) {
  node_t *temp;

  while (queue->front != NULL) {
    temp = queue->front;
    queue->front = temp->next;
    free(temp);
  }

  free(queue);
}

// Main function
int main() {
  // Create a new queue
  queue_t *queue = create_queue();

  // Enqueue some elements
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the queue
  printf("Queue: ");
  print_queue(queue);

  // Dequeue an element
  int data = dequeue(queue);

  // Print the dequeued element
  printf("Dequeued element: %d\n", data);

  // Print the queue
  printf("Queue: ");
  print_queue(queue);

  // Get the front element
  data = front(queue);

  // Print the front element
  printf("Front element: %d\n", data);

  // Get the rear element
  data = rear(queue);

  // Print the rear element
  printf("Rear element: %d\n", data);

  // Destroy the queue
  destroy_queue(queue);

  return 0;
}