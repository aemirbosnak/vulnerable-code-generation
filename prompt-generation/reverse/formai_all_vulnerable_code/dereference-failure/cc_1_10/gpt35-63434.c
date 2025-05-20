//FormAI DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

struct stack {
  int items[MAX_STACK_SIZE];
  int top;
};

typedef struct stack* Stack;

Stack create_new_stack() {
  Stack new_stack = (Stack) malloc(sizeof(struct stack));
  new_stack->top = -1;
  return new_stack;
}

bool is_empty(Stack stack) {
  return stack->top == -1;
}

bool is_full(Stack stack) {
  return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack stack, int item) {
  if(!is_full(stack)) {
    stack->top++;
    stack->items[stack->top] = item;
  }
}

int pop(Stack stack) {
  if(!is_empty(stack)) {
    int popped_item = stack->items[stack->top];
    stack->top--;
    return popped_item;
  }
}

void display(Stack stack) {
  int i;
  printf("\n\nStack\n\n");
  for(i=stack->top; i>=0; i--) {
    printf("%d\n", stack->items[i]);
  }
}

int main() {
  Stack stack = create_new_stack();

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  push(stack, 40);

  printf("After pushing 4 items onto the stack: \n");
  display(stack);

  pop(stack);

  printf("After popping an item from the stack: \n");
  display(stack);

  return 0;
}