//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
  int size;
  int top;
  int *array;
};

// A stack has a fixed size, we can create a stack
// of any size (within the memory limits)
struct Stack* createStack(int size) {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->size = size;
  stack->top = -1;
  stack->array = (int*)malloc(stack->size * sizeof(int));
  return stack;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
  return stack->top == stack->size - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
  return stack->top == -1;
}

// Push an element to the stack
void push(struct Stack* stack, int data) {
  if (isFull(stack)) {
    return;
  }
  stack->array[++stack->top] = data;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
  if (isEmpty(stack)) {
    return -1;
  }
  return stack->array[stack->top--];
}

// Print the stack
void printStack(struct Stack* stack) {
  for (int i = 0; i <= stack->top; i++) {
    printf("%d ", stack->array[i]);
  }
  printf("\n");
}

// Function to insert a disk into the stack
void insert(struct Stack* stack, int disk) {
  if (isEmpty(stack) || disk <= stack->array[stack->top]) {
    push(stack, disk);
  } else {
    printf("Cannot insert disk %d into stack %d\n", disk, stack->array[stack->top]);
  }
}

// Function to move a tower of disks from one stack to another
void move(struct Stack* from, struct Stack* to, int n) {
  if (n == 1) {
    push(to, pop(from));
    return;
  }

  // Create a temporary stack
  struct Stack* temp = createStack(n);

  // Move n-1 disks from the from stack to the temp stack
  for (int i = 1; i < n; i++) {
    push(temp, pop(from));
  }

  // Move the largest disk from the from stack to the to stack
  push(to, pop(from));

  // Move n-1 disks from the temp stack to the to stack
  for (int i = 1; i < n; i++) {
    push(to, pop(temp));
  }

  // Delete the temporary stack
  free(temp->array);
  free(temp);
}

// Main function
int main() {
  // Create three stacks
  struct Stack* stack1 = createStack(3);
  struct Stack* stack2 = createStack(3);
  struct Stack* stack3 = createStack(3);

  // Insert three disks into the first stack
  for (int i = 3; i >= 1; i--) {
    push(stack1, i);
  }

  // Print the initial state of the stacks
  printf("Initial state of the stacks:\n");
  printStack(stack1);
  printStack(stack2);
  printStack(stack3);

  // Move the tower of disks from the first stack to the third stack
  move(stack1, stack3, 3);

  // Print the final state of the stacks
  printf("\nFinal state of the stacks:\n");
  printStack(stack1);
  printStack(stack2);
  printStack(stack3);

  // Delete the stacks
  free(stack1->array);
  free(stack1);
  free(stack2->array);
  free(stack2);
  free(stack3->array);
  free(stack3);

  return 0;
}