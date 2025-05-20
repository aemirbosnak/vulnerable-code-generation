//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Node structure for a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to Free (destroy) the linked list
void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Stack structure using linked list
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack!\n", data);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow! Cannot pop!\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("Popped %d from the stack!\n", poppedValue);
    return poppedValue;
}

// Function to display the stack
void displayStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list and stack
int main() {
    Node* listHead = NULL;

    // Demonstrating Linked List Usage
    printf("=== Linked List Demonstration ===\n");
    insertEnd(&listHead, 10);
    insertEnd(&listHead, 20);
    insertEnd(&listHead, 30);
    displayList(listHead);

    // Free linked list memory
    freeList(listHead);

    // Demonstrating Stack Usage
    printf("\n=== Stack Demonstration ===\n");
    Stack* myStack = createStack();
    push(myStack, 5);
    push(myStack, 10);
    push(myStack, 15);
    displayStack(myStack);
    
    pop(myStack);
    displayStack(myStack);
    
    pop(myStack);
    displayStack(myStack);
    
    pop(myStack);
    pop(myStack); // Try popping from an empty stack

    // Clean up
    freeList(myStack->top); // Free stack nodes
    free(myStack);          // Free stack structure

    return 0;
}