//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for a linked list
struct Node {
    int data;                // The data stored in the node
    struct Node* next;      // A pointer to the next node in the list
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push a new node onto the front of the linked list
void push(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
    printf("Pushed %d into the list!\n", newData);
}

// Function to print the linked list
void printList(struct Node* node) {
    printf("Current Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// This is our mighty Stack structure built on top of the linked list!
struct Stack {
    struct Node* top; // Top of the stack
};

// Function to create the stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL; // Initially, the stack is empty
    return stack;
}

// Function to push an item onto the stack
void stackPush(struct Stack* stack, int newData) {
    push(&(stack->top), newData);
    printf("Stack currently has:");
    printList(stack->top);
}

// Function to pop an item off the stack
int stackPop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty! Cannot pop\n");
        return -1; // Indicating stack is empty
    }
    struct Node* tempNode = stack->top;
    int poppedData = tempNode->data;
    stack->top = stack->top->next; // Change top to point to the next node
    free(tempNode); // Free the popped node
    printf("Popped %d from the stack!\n", poppedData);
    return poppedData;
}

// Function to peek the top item of the stack
int stackPeek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Indicating stack is empty
    }
    return stack->top->data; // Return the top data
}

// Main function to demonstrate how our Stack works
int main() {
    struct Stack* myStack = createStack(); // Create a stack

    // Let's push some data onto our Stack!
    stackPush(myStack, 10);
    stackPush(myStack, 20);
    stackPush(myStack, 30);
    
    // Peek the top item
    printf("Top item in stack: %d\n", stackPeek(myStack));
    
    // Pop an item from the stack
    stackPop(myStack);
    
    // Peek again to see what's on top now
    printf("Top item in stack after pop: %d\n", stackPeek(myStack));

    // Let's pop all items to see how it behaves!
    stackPop(myStack);
    stackPop(myStack);
    stackPop(myStack); // Should indicate that it's empty now!

    // Clean up the stack itself
    free(myStack);
    
    return 0;
}