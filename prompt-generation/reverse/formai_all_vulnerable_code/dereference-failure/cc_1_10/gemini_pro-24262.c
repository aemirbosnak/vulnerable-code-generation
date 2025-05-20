//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
  char data;
  struct node *next;
} node_t;

typedef struct stack {
  node_t *top;
} stack_t;

stack_t *create_stack() {
  stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }
  stack->top = NULL;
  return stack;
}

void push(stack_t *stack, char data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    return;
  }
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
}

char pop(stack_t *stack) {
  if (stack->top == NULL) {
    return '\0';
  }
  char data = stack->top->data;
  node_t *temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return data;
}

int is_palindrome(char *string) {
  stack_t *stack = create_stack();
  int length = strlen(string);
  for (int i = 0; i < length / 2; i++) {
    push(stack, string[i]);
  }
  if (length % 2 == 1) {
    pop(stack);
  }
  for (int i = length / 2; i < length; i++) {
    if (pop(stack) != string[i]) {
      return FALSE;
    }
  }
  return TRUE;
}

int main(void) {
  char string[] = "racecar";
  if (is_palindrome(string)) {
    printf("%s is a palindrome.\n", string);
  } else {
    printf("%s is not a palindrome.\n", string);
  }
  return 0;
}