//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 1000

// Define the stack data structure
typedef struct stack {
  int top;
  int size;
  int *array;
} stack;

// Initialize the stack
void stack_init(stack *s) {
  s->top = -1;
  s->size = MAX_STACK_SIZE;
  s->array = malloc(s->size * sizeof(int));
}

// Push an element onto the stack
void stack_push(stack *s, int value) {
  if (s->top == s->size - 1) {
    // The stack is full, so we need to resize it
    s->size *= 2;
    s->array = realloc(s->array, s->size * sizeof(int));
  }
  s->array[++s->top] = value;
}

// Pop an element off the stack
int stack_pop(stack *s) {
  if (s->top == -1) {
    // The stack is empty, so there is nothing to pop
    return -1;
  }
  return s->array[s->top--];
}

// Print the stack
void stack_print(stack *s) {
  for (int i = 0; i <= s->top; i++) {
    printf("%d ", s->array[i]);
  }
  printf("\n");
}

// Recursively reverse a string using a stack
void reverse_string(char *str) {
  // Base case: the string is empty or has only one character
  if (strlen(str) == 0 || strlen(str) == 1) {
    return;
  }

  // Create a stack to store the characters of the string
  stack s;
  stack_init(&s);

  // Push the characters of the string onto the stack
  for (int i = 0; i < strlen(str); i++) {
    stack_push(&s, str[i]);
  }

  // Pop the characters off the stack and append them to the reversed string
  for (int i = 0; i < strlen(str); i++) {
    str[i] = stack_pop(&s);
  }
}

// Main function
int main() {
  // Create a stack
  stack s;
  stack_init(&s);

  // Push some elements onto the stack
  stack_push(&s, 1);
  stack_push(&s, 2);
  stack_push(&s, 3);
  stack_push(&s, 4);
  stack_push(&s, 5);

  // Print the stack
  stack_print(&s);

  // Pop an element off the stack
  int popped_element = stack_pop(&s);

  // Print the popped element
  printf("Popped element: %d\n", popped_element);

  // Print the stack
  stack_print(&s);

  // Reverse a string using a stack
  char str[] = "Hello, world!";
  reverse_string(str);
  printf("Reversed string: %s\n", str);

  return 0;
}