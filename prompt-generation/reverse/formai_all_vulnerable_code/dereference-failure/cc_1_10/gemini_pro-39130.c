//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A node in the queue
typedef struct _node {
  int data;
  struct _node *next;
} node;

// The queue itself
typedef struct _queue {
  node *head;
  node *tail;
  int size;
} queue;

// Create a new queue
queue *create_queue() {
  queue *q = malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  return q;
}

// Destroy a queue
void destroy_queue(queue *q) {
  node *current = q->head;
  while (current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
  }
  free(q);
}

// Enqueue an item
void enqueue(queue *q, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  if (q->tail == NULL) {
    q->head = new_node;
  } else {
    q->tail->next = new_node;
  }
  q->tail = new_node;
  q->size++;
}

// Dequeue an item
int dequeue(queue *q) {
  if (q->head == NULL) {
    return -1;
  }
  int data = q->head->data;
  node *old_head = q->head;
  q->head = q->head->next;
  if (q->head == NULL) {
    q->tail = NULL;
  }
  free(old_head);
  q->size--;
  return data;
}

// Peek at the front of the queue
int peek(queue *q) {
  if (q->head == NULL) {
    return -1;
  }
  return q->head->data;
}

// Is the queue empty?
int is_empty(queue *q) {
  return q->size == 0;
}

// Get the size of the queue
int size(queue *q) {
  return q->size;
}

// Print the queue
void print_queue(queue *q) {
  node *current = q->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  // Create a new queue
  queue *q = create_queue();

  // Enqueue some items
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);

  // Print the queue
  print_queue(q);

  // Dequeue some items
  printf("Dequeued: %d\n", dequeue(q));
  printf("Dequeued: %d\n", dequeue(q));
  printf("Dequeued: %d\n", dequeue(q));

  // Print the queue
  print_queue(q);

  // Destroy the queue
  destroy_queue(q);

  return 0;
}