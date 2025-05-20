//FormAI DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for each node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node and insert data into it
struct Node* createNode(int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertNode(struct Node** headRef, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = *headRef;
  *headRef = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** headRef, int data) {
  struct Node* current = *headRef;
  struct Node* prev = NULL;

  while (current != NULL && current->data != data) {
    prev = current;
    current = current->next;
  }
  if (current == NULL) {
    printf("Node not found in the linked list\n");
  } else {
    if (prev == NULL) {
      *headRef = current->next;
    } else {
      prev->next = current->next;
    }
    free(current);
    printf("Node with data %d deleted from the linked list\n", data);
  }
}

// Function to display the linked list
void displayList(struct Node* head) {
  printf("Current linked list: ");
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

// Function to create a new stack and push data into it
struct Stack {
  int top;
  unsigned capacity;
  int* array;
};

struct Stack* createStack(unsigned capacity) {
  struct Stack* stack = malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = malloc(stack->capacity * sizeof(int));
  return stack;
}

void push(struct Stack* stack, int data) {
  if (stack->top == stack->capacity - 1) {
    printf("Stack overflow! \n");
    return;
  }
  stack->top++;
  stack->array[stack->top] = data;
  printf("%d was pushed into the stack \n", data);
}

// Function to pop a data from the stack
int pop(struct Stack* stack) {
  if (stack->top == -1) {
    printf("Stack is empty! \n");
    return -1;
  }
  int data = stack->array[stack->top];
  stack->top--;
  printf("%d was popped from the stack \n", data);
  return data;
}

// Function to display the stack
void displayStack(struct Stack* stack) {
  printf("Current stack: ");
  int i;
  for (i = 0; i <= stack->top; i++) { 
    printf("%d -> ", stack->array[i]);
  }
  printf("NULL\n");
}

int main() {
  struct Node* head = NULL; // Initialize an empty linked list

  insertNode(&head, 8);
  insertNode(&head, 23);
  insertNode(&head, 6);
  insertNode(&head, 89);
  insertNode(&head, 12);
  insertNode(&head, 72);

  displayList(head);

  deleteNode(&head, 6);
  deleteNode(&head, 12);

  displayList(head);

  // Initialize a stack with capacity 5
  struct Stack* stack = createStack(5);

  push(stack, 3);
  push(stack, 5);
  push(stack, 7);
  push(stack, 2);

  displayStack(stack);

  pop(stack);
  pop(stack);

  displayStack(stack);

  return 0;
}