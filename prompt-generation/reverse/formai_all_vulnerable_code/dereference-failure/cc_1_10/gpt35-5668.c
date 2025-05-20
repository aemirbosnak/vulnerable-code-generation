//FormAI DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a node in the queue
struct Node {
  int data;
  struct Node* next;
};

// Defining the structure of the queue
struct Queue {
  struct Node* front;
  struct Node* rear;
};

// Function to create a node
struct Node* create_node(int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to initialize the queue
struct Queue* create_queue() {
  struct Queue* new_queue = (struct Queue*)malloc(sizeof(struct Queue));
  new_queue->front = new_queue->rear = NULL;
  return new_queue;
}

// Function to check if the queue is empty
int is_empty(struct Queue* queue) {
  return queue->front == NULL;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue* queue, int data) {
  struct Node* new_node = create_node(data);

  if (is_empty(queue)) {
    queue->front = queue->rear = new_node;
    return;
  }

  queue->rear->next = new_node;
  queue->rear = new_node;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
  if (is_empty(queue)) {
    printf("Queue is empty\n");
    return -1;
  }

  struct Node* temp = queue->front;
  int data = temp->data;
  queue->front = queue->front->next;

  if (queue->front == NULL)
    queue->rear = NULL;

  free(temp);
  return data;
}

// Function to print the queue
void print_queue(struct Queue* queue) {
  if (is_empty(queue)) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue: ");
  struct Node* current = queue->front;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Main function to test the queue implementation
int main() {
  struct Queue* queue = create_queue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  printf("Dequeued: %d\n", dequeue(queue));

  enqueue(queue, 4);
  enqueue(queue, 5);

  print_queue(queue);

  return 0;
}