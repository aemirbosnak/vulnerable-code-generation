//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a queue element
struct queue_element {
  int data;
  struct queue_element *next;
};

// Defining the structure of a queue
struct queue {
  struct queue_element *head;
  struct queue_element *tail;
};

// Function to create a new queue
struct queue *create_queue() {
  struct queue *new_queue = (struct queue *)malloc(sizeof(struct queue));
  new_queue->head = NULL;
  new_queue->tail = NULL;
  return new_queue;
}

// Function to enqueue an element into a queue
void enqueue(struct queue *queue, int data) {
  struct queue_element *new_element = (struct queue_element *)malloc(sizeof(struct queue_element));
  new_element->data = data;
  new_element->next = NULL;

  if (queue->head == NULL) {
    queue->head = new_element;
  } else {
    queue->tail->next = new_element;
  }
  queue->tail = new_element;
}

// Function to dequeue an element from a queue
int dequeue(struct queue *queue) {
  if (queue->head == NULL) {
    return -1; // Queue is empty, return -1
  }

  int data = queue->head->data;
  struct queue_element *temp = queue->head;
  queue->head = queue->head->next;
  free(temp);

  if (queue->head == NULL) {
    queue->tail = NULL;
  }

  return data;
}

// Function to print the elements of a queue
void print_queue(struct queue *queue) {
  struct queue_element *current = queue->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Function to test the queue implementation
int main() {
  // Creating a new queue
  struct queue *queue = create_queue();

  // Enqueueing elements into the queue
  printf("Enqueueing elements into the queue:\n");
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);
  print_queue(queue);

  // Dequeueing elements from the queue
  printf("\nDequeueing elements from the queue:\n");
  printf("%d\n", dequeue(queue));
  printf("%d\n", dequeue(queue));
  printf("%d\n", dequeue(queue));
  print_queue(queue);

  return 0;
}