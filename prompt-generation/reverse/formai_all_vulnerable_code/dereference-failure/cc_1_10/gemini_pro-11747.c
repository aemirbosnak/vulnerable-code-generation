//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// A queue is a first-in, first-out (FIFO) data structure.
// It follows the following operations:
// - enqueue: add an element to the end of the queue.
// - dequeue: remove an element from the front of the queue.
// - peek: return the first element of the queue without removing it.
// - is_empty: check if the queue is empty.

// A node in the queue.
typedef struct node {
  int data;
  struct node *next;
} node_t;

// The queue itself.
typedef struct queue {
  node_t *head;
  node_t *tail;
} queue_t;

// Create a new queue.
queue_t *create_queue() {
  queue_t *queue = malloc(sizeof(queue_t));
  if (queue == NULL) {
    return NULL;
  }
  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

// Destroy a queue.
void destroy_queue(queue_t *queue) {
  node_t *current_node = queue->head;
  while (current_node != NULL) {
    node_t *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
  free(queue);
}

// Enqueue an element to the end of the queue.
void enqueue(queue_t *queue, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  if (new_node == NULL) {
    return;
  }
  new_node->data = data;
  new_node->next = NULL;
  if (queue->head == NULL) {
    queue->head = new_node;
  } else {
    queue->tail->next = new_node;
  }
  queue->tail = new_node;
}

// Dequeue an element from the front of the queue.
int dequeue(queue_t *queue) {
  if (queue->head == NULL) {
    return -1;  // Queue is empty.
  }
  node_t *current_node = queue->head;
  int data = current_node->data;
  queue->head = current_node->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }
  free(current_node);
  return data;
}

// Peek the first element of the queue without removing it.
int peek(queue_t *queue) {
  if (queue->head == NULL) {
    return -1;  // Queue is empty.
  }
  return queue->head->data;
}

// Check if the queue is empty.
int is_empty(queue_t *queue) {
  return queue->head == NULL;
}

// Print the queue.
void print_queue(queue_t *queue) {
  node_t *current_node = queue->head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// Test the queue.
int main() {
  queue_t *queue = create_queue();
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  print_queue(queue);  // Output: 1 2 3

  int data = dequeue(queue);
  printf("Dequeued: %d\n", data);  // Output: Dequeued: 1

  data = peek(queue);
  printf("Peeked: %d\n", data);  // Output: Peeked: 2

  printf("Is empty: %d\n", is_empty(queue));  // Output: Is empty: 0

  destroy_queue(queue);

  return 0;
}