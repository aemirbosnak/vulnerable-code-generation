//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
struct Node {
  int data;
  struct Node *next;
};

// Define the structure of the queue
struct Queue {
  struct Node *head;
  struct Node *tail;
  int size;
};

// Create a new queue
struct Queue *create_queue() {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

// Check if the queue is empty
int is_queue_empty(struct Queue *queue) {
  return queue->size == 0;
}

// Enqueue an element into the queue
void enqueue(struct Queue *queue, int data) {
  // Create a new node
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;

  // If the queue is empty, set the head and tail to the new node
  if (is_queue_empty(queue)) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    // Add the new node to the end of the queue
    queue->tail->next = new_node;
    queue->tail = new_node;
  }

  // Increment the size of the queue
  queue->size++;
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
  // If the queue is empty, return -1
  if (is_queue_empty(queue)) {
    return -1;
  }

  // Get the data from the head of the queue
  int data = queue->head->data;

  // Remove the head node from the queue
  struct Node *old_head = queue->head;
  queue->head = queue->head->next;

  // If the queue is now empty, set the tail to NULL
  if (is_queue_empty(queue)) {
    queue->tail = NULL;
  }

  // Free the old head node
  free(old_head);

  // Decrement the size of the queue
  queue->size--;

  // Return the data from the head of the queue
  return data;
}

// Peek at the front element of the queue
int peek(struct Queue *queue) {
  // If the queue is empty, return -1
  if (is_queue_empty(queue)) {
    return -1;
  }

  // Return the data from the head of the queue
  return queue->head->data;
}

// Print the elements of the queue
void print_queue(struct Queue *queue) {
  struct Node *current_node = queue->head;

  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }

  printf("\n");
}

// Free the memory allocated for the queue
void free_queue(struct Queue *queue) {
  struct Node *current_node = queue->head;

  while (current_node != NULL) {
    struct Node *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }

  free(queue);
}

// Test the queue implementation
int main() {
  // Create a new queue
  struct Queue *queue = create_queue();

  // Enqueue some elements into the queue
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);

  // Print the elements of the queue
  printf("The elements of the queue are: ");
  print_queue(queue);

  // Dequeue an element from the queue
  int dequeued_element = dequeue(queue);

  // Print the dequeued element
  printf("The dequeued element is: %d\n", dequeued_element);

  // Peek at the front element of the queue
  int peeked_element = peek(queue);

  // Print the peeked element
  printf("The peeked element is: %d\n", peeked_element);

  // Free the memory allocated for the queue
  free_queue(queue);

  return 0;
}