//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack {
  int *arr;
  int top;
  int capacity;
} Stack;

// Function to create a stack of given capacity
Stack *createStack(int capacity) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->arr = (int *)malloc(sizeof(int) * capacity);
  stack->top = -1;
  stack->capacity = capacity;
  return stack;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
  return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
  return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int item) {
  if (isFull(stack)) {
    printf("Stack is full!\n");
    return;
  }
  stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty!\n");
    return -1;
  }
  return stack->arr[stack->top--];
}

// Function to move a disk from one stack to another
void moveDisk(Stack *from, Stack *to) {
  int disk = pop(from);
  push(to, disk);
  printf("Moved disk %d from %c to %c\n", disk, from->arr[0], to->arr[0]);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, Stack *from, Stack *to, Stack *aux) {
  if (n == 1) {
    moveDisk(from, to);
    return;
  }
  towerOfHanoi(n - 1, from, aux, to);
  moveDisk(from, to);
  towerOfHanoi(n - 1, aux, to, from);
}

// Main function
int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  // Create three stacks
  Stack *from = createStack(n);
  Stack *to = createStack(n);
  Stack *aux = createStack(n);

  // Initialize the 'from' stack with the disks
  for (int i = n; i >= 1; i--) {
    push(from, i);
  }

  // Print the initial state of the stacks
  printf("Initial state:\n");
  printf("From: ");
  for (int i = from->top; i >= 0; i--) {
    printf("%d ", from->arr[i]);
  }
  printf("\n");
  printf("To: ");
  for (int i = to->top; i >= 0; i--) {
    printf("%d ", to->arr[i]);
  }
  printf("\n");
  printf("Aux: ");
  for (int i = aux->top; i >= 0; i--) {
    printf("%d ", aux->arr[i]);
  }
  printf("\n");

  // Solve the Tower of Hanoi problem
  towerOfHanoi(n, from, to, aux);

  // Print the final state of the stacks
  printf("Final state:\n");
  printf("From: ");
  for (int i = from->top; i >= 0; i--) {
    printf("%d ", from->arr[i]);
  }
  printf("\n");
  printf("To: ");
  for (int i = to->top; i >= 0; i--) {
    printf("%d ", to->arr[i]);
  }
  printf("\n");
  printf("Aux: ");
  for (int i = aux->top; i >= 0; i--) {
    printf("%d ", aux->arr[i]);
  }
  printf("\n");

  return 0;
}