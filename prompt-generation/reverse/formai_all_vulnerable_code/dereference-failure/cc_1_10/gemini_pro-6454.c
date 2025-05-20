//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
// Ada Lovelace's Analytical Engine Data Structures Visualization Example

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Data Structures
typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct stack {
  Node *top;
  int size;
} Stack;

typedef struct queue {
  Node *front, *rear;
  int size;
} Queue;

// Helper Functions
Node* create_node(int data) {
  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void push(Stack *stack, int data) {
  Node *new_node = create_node(data);
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
}

int pop(Stack *stack) {
  if (stack->size == 0) {
    return -1; // Stack is empty
  }
  Node *temp = stack->top;
  int data = temp->data;
  stack->top = temp->next;
  free(temp);
  stack->size--;
  return data;
}

void enqueue(Queue *queue, int data) {
  Node *new_node = create_node(data);
  if (queue->front == NULL) {
    queue->front = new_node;
    queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
  queue->size++;
}

int dequeue(Queue *queue) {
  if (queue->size == 0) {
    return -1; // Queue is empty
  }
  Node *temp = queue->front;
  int data = temp->data;
  queue->front = temp->next;
  free(temp);
  queue->size--;
  return data;
}

// Main Function
int main() {
  // Initialize data structures
  Stack stack;
  stack.top = NULL;
  stack.size = 0;

  Queue queue;
  queue.front = NULL;
  queue.rear = NULL;
  queue.size = 0;

  // Push and pop values into the stack
  printf("Pushing values into the stack: ");
  for (int i = 1; i <= 5; i++) {
    push(&stack, i);
    printf("%d ", i);
  }
  printf("\n");

  // Pop and print values from the stack
  printf("Popping values from the stack: ");
  while (stack.size > 0) {
    printf("%d ", pop(&stack));
  }
  printf("\n");

  // Enqueue and dequeue values into the queue
  printf("Enqueueing values into the queue: ");
  for (int i = 1; i <= 5; i++) {
    enqueue(&queue, i);
    printf("%d ", i);
  }
  printf("\n");

  // Dequeue and print values from the queue
  printf("Dequeueing values from the queue: ");
  while (queue.size > 0) {
    printf("%d ", dequeue(&queue));
  }
  printf("\n");

  return 0;
}