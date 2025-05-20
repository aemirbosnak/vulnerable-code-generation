//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack {
  int *arr;
  int top;
  unsigned capacity;
} Stack;

// Function to create a stack of given capacity
Stack *createStack(unsigned capacity) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->arr = (int *)malloc(stack->capacity * sizeof(int));
  return stack;
}

// Function to push an item to the stack
void push(Stack *stack, int item) {
  if (stack->top == stack->capacity - 1) {
    printf("Stack Overflow\n");
    return;
  }
  stack->arr[++stack->top] = item;
  printf("%d pushed to stack\n", item);
}

// Function to pop an item from the stack
int pop(Stack *stack) {
  if (stack->top == -1) {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack->arr[stack->top--];
}

// Function to insert a disk into the pole
void insertDisk(int disk, int pole) {
  printf("Inserting disk %d into pole %d\n", disk, pole);
}

// Function to solve the Tower of Hanoi problem using stacks
void towerOfHanoi(int numDisks, int fromPole, int toPole, int auxPole) {
  // Base case: Only one disk
  if (numDisks == 1) {
    insertDisk(1, fromPole);
    insertDisk(1, toPole);
    return;
  }

  // Move numDisks-1 disks from the fromPole to the auxPole
  towerOfHanoi(numDisks - 1, fromPole, auxPole, toPole);

  // Move the largest disk from the fromPole to the toPole
  insertDisk(numDisks, fromPole);
  insertDisk(numDisks, toPole);

  // Move numDisks-1 disks from the auxPole to the toPole
  towerOfHanoi(numDisks - 1, auxPole, toPole, fromPole);
}

// Main function
int main() {
  int numDisks;

  // Get the number of disks
  printf("Enter the number of disks: ");
  scanf("%d", &numDisks);

  // Create three stacks to represent the three poles
  Stack *fromPole = createStack(numDisks);
  Stack *toPole = createStack(numDisks);
  Stack *auxPole = createStack(numDisks);

  // Move the disks from the fromPole to the toPole
  towerOfHanoi(numDisks, fromPole->top, toPole->top, auxPole->top);

  return 0;
}