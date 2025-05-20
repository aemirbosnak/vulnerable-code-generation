//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
  int top;
  unsigned capacity;
  int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  return stack;
}

// Function to push an item into the stack
void push(struct Stack* stack, int item) {
  if (stack->top == stack->capacity - 1) {
    printf("Stack is full!\n");
    return;
  }
  stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
  if (stack->top == -1) {
    printf("Stack is empty!\n");
    return -1;
  }
  return stack->array[stack->top--];
}

// Function to implement the Tower of Hanoi problem using stacks
void towerOfHanoi(int n, struct Stack* from, struct Stack* to, struct Stack* aux) {
  // Base case: when there is only one disk
  if (n == 1) {
    push(to, pop(from));
    return;
  }

  // Move the top n-1 disks from the "from" rod to the "aux" rod
  towerOfHanoi(n - 1, from, aux, to);

  // Move the largest disk from the "from" rod to the "to" rod
  push(to, pop(from));

  // Move the n-1 disks from the "aux" rod to the "to" rod
  towerOfHanoi(n - 1, aux, to, from);
}

// Function to print the contents of the stack
void printStack(struct Stack* stack) {
  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  // Create three stacks
  struct Stack* from = createStack(3);
  struct Stack* to = createStack(3);
  struct Stack* aux = createStack(3);

  // Push the disks onto the "from" rod
  for (int i = 3; i >= 1; i--) {
    push(from, i);
  }

  // Print the initial state of the stacks
  printf("Initial state of the stacks:\n");
  printf("From: ");
  printStack(from);
  printf("To: ");
  printStack(to);
  printf("Aux: ");
  printStack(aux);

  // Solve the Tower of Hanoi problem
  towerOfHanoi(3, from, to, aux);

  // Print the final state of the stacks
  printf("\nFinal state of the stacks:\n");
  printf("From: ");
  printStack(from);
  printf("To: ");
  printStack(to);
  printf("Aux: ");
  printStack(aux);

  return 0;
}