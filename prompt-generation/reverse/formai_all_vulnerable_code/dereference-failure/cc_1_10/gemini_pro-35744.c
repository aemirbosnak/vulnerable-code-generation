//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack.
#define MAX_STACK_SIZE 100

// Define the structure of a stack node.
typedef struct stack_node {
  int data;
  struct stack_node *next;
} stack_node;

// Define the head of the stack.
stack_node *head = NULL;

// Push an element onto the stack.
void push(int data) {
  // Create a new stack node.
  stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));

  // Set the data of the new node.
  new_node->data = data;

  // Set the next pointer of the new node to the current head of the stack.
  new_node->next = head;

  // Set the head of the stack to the new node.
  head = new_node;
}

// Pop an element from the stack.
int pop() {
  // Check if the stack is empty.
  if (head == NULL) {
    return -1;
  }

  // Get the data from the head of the stack.
  int data = head->data;

  // Set the head of the stack to the next node.
  head = head->next;

  // Free the memory allocated for the old head of the stack.
  free(head);

  // Return the data from the stack.
  return data;
}

// Print the stack.
void print_stack() {
  // Create a temporary pointer to the head of the stack.
  stack_node *temp = head;

  // Print the data from each node in the stack.
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  // Print a newline character.
  printf("\n");
}

// Reverse a string using a stack.
char *reverse_string(char *str) {
  // Create a stack.
  stack_node *stack = NULL;

  // Push each character of the string onto the stack.
  for (int i = 0; i < strlen(str); i++) {
    push(str[i]);
  }

  // Create a new string to store the reversed string.
  char *reversed_str = (char *)malloc(strlen(str) + 1);

  // Pop each character from the stack and append it to the reversed string.
  for (int i = 0; i < strlen(str); i++) {
    reversed_str[i] = pop();
  }

  // Add a null terminator to the end of the reversed string.
  reversed_str[strlen(str)] = '\0';

  // Return the reversed string.
  return reversed_str;
}

// Main function.
int main() {
  // Push some elements onto the stack.
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  // Print the stack.
  printf("Stack: ");
  print_stack();

  // Pop some elements from the stack.
  pop();
  pop();

  // Print the stack.
  printf("Stack: ");
  print_stack();

  // Reverse a string using a stack.
  char *str = "Hello world!";
  char *reversed_str = reverse_string(str);

  // Print the original string and the reversed string.
  printf("Original string: %s\n", str);
  printf("Reversed string: %s\n", reversed_str);

  // Free the memory allocated for the reversed string.
  free(reversed_str);

  return 0;
}