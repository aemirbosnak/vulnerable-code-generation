//FormAI DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Stack {
  int* arr;
  int top;
} Stack;

Stack* createStack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->arr = (int*)malloc(sizeof(int) * MAX_SIZE);
  stack->top = -1;
  return stack;
}

bool isEmpty(Stack* stack) {
  return stack->top == -1;
}

bool isFull(Stack* stack) {
  return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int data) {
  if (isFull(stack)) {
    printf("Stack overflow!\n");
    return;
  }
  stack->arr[++stack->top] = data;
}

int pop(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow!\n");
    return -1;
  }
  return stack->arr[stack->top--];
}

void display(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty.\n");
    return;
  }
  printf("Stack: ");
  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->arr[i]);
  }
  printf("\n");
}

int main() {
  Stack* stack = createStack();
  
  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  
  display(stack);
  
  pop(stack);
  
  display(stack);
  
  free(stack->arr);
  free(stack);
  
  return 0;
}