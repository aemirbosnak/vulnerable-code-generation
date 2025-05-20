//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// A queue is like a line of people waiting for something.
// The first person in line gets to go first.
// We'll use an array to represent the queue.

#define QUEUE_SIZE 100

// The queue is made up of nodes.
// Each node has a value and a pointer to the next node.
typedef struct node {
  int value;
  struct node *next;
} node_t;

// The queue has a head and a tail.
// The head is the first node in the queue.
// The tail is the last node in the queue.
typedef struct queue {
  node_t *head;
  node_t *tail;
} queue_t;

// Create a new queue.
queue_t *create_queue() {
  queue_t *queue = malloc(sizeof(queue_t));
  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

// Destroy a queue.
void destroy_queue(queue_t *queue) {
  while (queue->head != NULL) {
    node_t *node = queue->head;
    queue->head = node->next;
    free(node);
  }
  free(queue);
}

// Add an item to the end of the queue.
void enqueue(queue_t *queue, int value) {
  node_t *node = malloc(sizeof(node_t));
  node->value = value;
  node->next = NULL;
  if (queue->tail == NULL) {
    queue->head = node;
    queue->tail = node;
  } else {
    queue->tail->next = node;
    queue->tail = node;
  }
}

// Remove an item from the front of the queue.
int dequeue(queue_t *queue) {
  if (queue->head == NULL) {
    return -1;  // Queue is empty.
  } else {
    int value = queue->head->value;
    node_t *node = queue->head;
    queue->head = node->next;
    if (queue->head == NULL) {
      queue->tail = NULL;
    }
    free(node);
    return value;
  }
}

// Print the queue.
void print_queue(queue_t *queue) {
  node_t *node = queue->head;
  while (node != NULL) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}

// Main function.
int main() {
  // Create a new queue.
  queue_t *queue = create_queue();

  // Add some items to the queue.
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the queue.
  print_queue(queue);

  // Remove some items from the queue.
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  // Print the queue again.
  print_queue(queue);

  // Destroy the queue.
  destroy_queue(queue);

  return 0;
}