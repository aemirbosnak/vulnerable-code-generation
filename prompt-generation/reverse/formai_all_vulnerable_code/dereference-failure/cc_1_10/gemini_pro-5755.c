//GEMINI-pro DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack and queue
#define STACK_SIZE 100
#define QUEUE_SIZE 100

// Define the node structure for the stack and queue
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Define the stack structure
typedef struct stack {
  node_t *top;
  int size;
} stack_t;

// Define the queue structure
typedef struct queue {
  node_t *front;
  node_t *rear;
  int size;
} queue_t;

// Initialize the stack
stack_t *init_stack() {
  stack_t *stack = malloc(sizeof(stack_t));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

// Initialize the queue
queue_t *init_queue() {
  queue_t *queue = malloc(sizeof(queue_t));
  queue->front = NULL;
  queue->rear = NULL;
  queue->size = 0;
  return queue;
}

// Push an element to the stack
void push(stack_t *stack, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
}

// Pop an element from the stack
int pop(stack_t *stack) {
  if (stack->size == 0) {
    printf("Stack is empty\n");
    return -1;
  }
  node_t *temp = stack->top;
  int data = temp->data;
  stack->top = stack->top->next;
  free(temp);
  stack->size--;
  return data;
}

// Enqueue an element to the queue
void enqueue(queue_t *queue, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  if (queue->rear == NULL) {
    queue->front = new_node;
    queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
  queue->size++;
}

// Dequeue an element from the queue
int dequeue(queue_t *queue) {
  if (queue->size == 0) {
    printf("Queue is empty\n");
    return -1;
  }
  node_t *temp = queue->front;
  int data = temp->data;
  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }
  free(temp);
  queue->size--;
  return data;
}

// Print the stack
void print_stack(stack_t *stack) {
  node_t *temp = stack->top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
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

// Test the stack and queue
int main() {
  stack_t *stack = init_stack();
  queue_t *queue = init_queue();

  // Push elements to the stack
  for (int i = 0; i < 5; i++) {
    push(stack, i);
  }

  // Print the stack
  printf("Stack: ");
  print_stack(stack);

  // Pop elements from the stack
  for (int i = 0; i < 5; i++) {
    printf("%d ", pop(stack));
  }
  printf("\n");

  // Enqueue elements to the queue
  for (int i = 0; i < 5; i++) {
    enqueue(queue, i);
  }

  // Print the queue
  printf("Queue: ");
  print_queue(queue);

  // Dequeue elements from the queue
  for (int i = 0; i < 5; i++) {
    printf("%d ", dequeue(queue));
  }
  printf("\n");

  return 0;
}