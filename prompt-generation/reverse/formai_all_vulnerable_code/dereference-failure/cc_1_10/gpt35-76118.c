//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// A struct to represent our stack data structure
typedef struct stack {
  int data[MAX_SIZE];
  int top;
} Stack;

// Initialize the stack's top to -1 to represent an empty stack
Stack* initStack() {
  Stack* s = malloc(sizeof(Stack));
  s->top = -1;
  return s;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
  return s->top == -1;
}

// Check if the stack is full
int isFull(Stack* s) {
  return s->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack* s, int value) {
  if (isFull(s)) {
    printf("Stack overflow, cannot push element onto stack.\n");
    return;
  }

  s->data[++s->top] = value;
}

// Pop the top element from the stack
int pop(Stack* s) {
  if (isEmpty(s)) {
    printf("Stack underflow, cannot pop element from stack.\n");
    return -1;
  }

  return s->data[s->top--];
}

// Print the contents of the stack
void printStack(Stack* s) {
  printf("Stack: ");

  for (int i = 0; i <= s->top; i++) {
    printf("%d ", s->data[i]);
  }

  printf("\n");
}

int main() {
  Stack* s = initStack();

  // Push elements onto the stack
  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  // Print the stack before popping elements
  printStack(s);

  // Pop elements off the stack
  printf("Popped element: %d\n", pop(s));
  printf("Popped element: %d\n", pop(s));

  // Print the stack after popping elements
  printStack(s);

  return 0;
}