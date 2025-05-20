//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack {
  int top;
  unsigned capacity;
  int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned capacity) {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  return stack;
}

// Function to push an item to the stack
void push(Stack* stack, int item) {
  if (stack->top == stack->capacity - 1) {
    printf("Stack is full!\n");
    return;
  }
  stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(Stack* stack) {
  if (stack->top == -1) {
    printf("Stack is empty!\n");
    return -1;
  }
  return stack->array[stack->top--];
}

// Function to move n disks from source to destination using an auxiliary tower
void towerOfHanoi(int n, Stack* source, Stack* destination, Stack* auxiliary) {
  if (n == 1) {
    push(destination, pop(source));
    return;
  }

  // Move n-1 disks from source to auxiliary tower
  towerOfHanoi(n - 1, source, auxiliary, destination);

  // Move the largest disk from source to destination
  push(destination, pop(source));

  // Move n-1 disks from auxiliary tower to destination
  towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Function to print the contents of the stack
void printStack(Stack* stack) {
  if (stack->top == -1) {
    printf("Stack is empty!\n");
    return;
  }

  for (int i = 0; i <= stack->top; i++) {
    printf("%d ", stack->array[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  // Create three stacks
  Stack* source = createStack(n);
  Stack* destination = createStack(n);
  Stack* auxiliary = createStack(n);

  // Push disks onto the source stack
  for (int i = n; i >= 1; i--) {
    push(source, i);
  }

  // Print the contents of the stacks before moving the disks
  printf("Initial state:\n");
  printf("Source stack: ");
  printStack(source);
  printf("Destination stack: ");
  printStack(destination);
  printf("Auxiliary stack: ");
  printStack(auxiliary);

  // Move the disks from the source stack to the destination stack using the auxiliary stack
  towerOfHanoi(n, source, destination, auxiliary);

  // Print the contents of the stacks after moving the disks
  printf("\nFinal state:\n");
  printf("Source stack: ");
  printStack(source);
  printf("Destination stack: ");
  printStack(destination);
  printf("Auxiliary stack: ");
  printStack(auxiliary);

  return 0;
}