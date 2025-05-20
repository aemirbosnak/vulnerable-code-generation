//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdlib.h>
#include <stdio.h>

// Define the node structure
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Define the queue structure
typedef struct queue {
  node_t *head;
  node_t *tail;
  int size;
} queue_t;

// Create a new queue
queue_t *create_queue() {
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

// Destroy a queue
void destroy_queue(queue_t *queue) {
  node_t *current = queue->head;
  while (current != NULL) {
    node_t *next = current->next;
    free(current);
    current = next;
  }
  free(queue);
}

// Enqueue an item
void enqueue(queue_t *queue, int item) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = item;
  new_node->next = NULL;

  if (queue->tail == NULL) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }

  queue->size++;
}

// Dequeue an item
int dequeue(queue_t *queue) {
  if (queue->head == NULL) {
    return -1;
  }

  int item = queue->head->data;
  node_t *next = queue->head->next;
  free(queue->head);
  queue->head = next;

  if (queue->head == NULL) {
    queue->tail = NULL;
  }

  queue->size--;
  return item;
}

// Get the size of the queue
int get_size(queue_t *queue) {
  return queue->size;
}

// Print the queue
void print_queue(queue_t *queue) {
  node_t *current = queue->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Test the queue
int main() {
  queue_t *queue = create_queue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  print_queue(queue);

  dequeue(queue);
  dequeue(queue);

  print_queue(queue);

  printf("Size of the queue: %d\n", get_size(queue));

  destroy_queue(queue);

  return 0;
}