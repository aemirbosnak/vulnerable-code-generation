//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000 // Define maximum size of stack

// Structure of each node in the stack
typedef struct node {
  char *data;          // Tag content
  struct node *next;   // Next node pointer
} Node;

// Structure of the stack
typedef struct stack {
  Node *top;           // Top node pointer
  int size;            // Current stack size
} Stack;

// Create an empty stack
Stack* createStack() {
  Stack *stack = (Stack*) malloc(sizeof(Stack));
  stack->size = 0;
  stack->top = NULL;
  return stack;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
  return stack->size == 0;
}

// Push the tag content onto the stack
void push(Stack *stack, char *data) {
  Node *node = (Node*) malloc(sizeof(Node));
  node->data = strdup(data);
  node->next = stack->top;
  stack->top = node;
  stack->size++;
}

// Pop the tag content from the stack
char* pop(Stack *stack) {
  if (isEmpty(stack)) {
    return NULL;
  }
  Node *node = stack->top;
  char *data = node->data;
  stack->top = node->next;
  stack->size--;
  free(node);
  return data;
}

// Beautify the given HTML code
char* beautifyHTML(char *html) {
  Stack *stack = createStack();
  char *beautified = (char*) malloc(strlen(html) * 2);
  char *token = strtok(html, "<>");
  while (token != NULL) {
    if (token[0] == '/') {
      char *tag = pop(stack);
      while (strcmp(tag, &token[1]) != 0) {
        sprintf(beautified, "%s</%s>\n", beautified, tag);
        free(tag);
        tag = pop(stack);
      }
      free(tag);
    } else {
      push(stack, strdup(token));
      int i;
      for (i = 0; i < stack->size - 1; i++) {
        sprintf(beautified, "%s  ", beautified);
      }
      sprintf(beautified, "%s<%s>\n", beautified, token);
    }
    token = strtok(NULL, "<>");
  }
  while (!isEmpty(stack)) {
    char *tag = pop(stack);
    sprintf(beautified, "%s</%s>\n", beautified, tag);
    free(tag);
  }
  free(stack);
  return beautified;
}

int main() {
  char html[] = "<html><head><title>Example</title></head><body><h1>Hello, world!</h1></body></html>";
  char *beautified = beautifyHTML(html);
  printf("%s", beautified);
  free(beautified);
  return 0;
}