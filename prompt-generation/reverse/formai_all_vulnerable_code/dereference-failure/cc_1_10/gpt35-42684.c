//FormAI DATASET v1.0 Category: Data structures visualization ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define the Stack data structure
struct Stack {
  int data[MAX_SIZE];
  int top;
};

// Create a new Stack data structure
struct Stack* createStack() {
  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
  stack->top = -1;
  return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
  return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
  return stack->top == MAX_SIZE - 1;
}

// Push an element to the stack
void push(struct Stack* stack, int x) {
  if (isFull(stack)) {
    printf("Error: Stack is full\n");
  } else {
    stack->data[++stack->top] = x;
  }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
  if (isEmpty(stack)) {
    printf("Error: Stack is empty\n");
    return -1;
  } else {
    return stack->data[stack->top--];
  }
}

// Visualize the stack data structure
void visualizeStack(struct Stack* stack) {
  int i, j;
  for (i = MAX_SIZE - 1; i >= 0; i--) {
    if (i == stack->top) {
      printf("%d\t<-- top\n", stack->data[i]);
    } else {
      printf("%d\n", stack->data[i]);
    }
  }
}

int main() {
  // Create a new Stack data structure
  struct Stack* stack = createStack();

  // Push some elements to the Stack
  push(stack, 10);
  push(stack, 20);
  push(stack, 30);

  // Visualize the Stack data structure
  visualizeStack(stack);

  // Pop an element from the Stack
  int x = pop(stack);
  printf("Popped element: %d\n", x);

  // Visualize the Stack data structure
  visualizeStack(stack);

  return 0;
}