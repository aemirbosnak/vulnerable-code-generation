//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

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
  while (queue->head != NULL) {
    node_t *temp = queue->head;
    queue->head = temp->next;
    free(temp);
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
  } else {
    queue->tail->next = new_node;
  }
  queue->tail = new_node;
  queue->size++;
}

// Dequeue an item
int dequeue(queue_t *queue) {
  if (queue->head == NULL) {
    return -1;
  }

  int item = queue->head->data;
  node_t *temp = queue->head;
  queue->head = temp->next;
  free(temp);
  queue->size--;

  return item;
}

// Get the size of the queue
int queue_size(queue_t *queue) {
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

// Main function
int main() {
  // Create a queue
  queue_t *queue = create_queue();

  // Enqueue some items
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the queue
  printf("Queue: ");
  print_queue(queue);

  // Dequeue some items
  int item1 = dequeue(queue);
  int item2 = dequeue(queue);
  int item3 = dequeue(queue);

  // Print the queue again
  printf("Queue after dequeueing 3 items: ");
  print_queue(queue);

  // Get the size of the queue
  int size = queue_size(queue);
  printf("Size of the queue: %d\n", size);

  // Destroy the queue
  destroy_queue(queue);

  return 0;
}