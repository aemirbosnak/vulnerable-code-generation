//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

//Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

//Stack structure definition using linked list
typedef struct stack {
    Node* top;
} Stack;

//Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to create an empty stack
Stack* createStack() {
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    if (!newStack) {
        printf("Memory error\n");
        exit(0);
    }
    newStack->top = NULL;
    return newStack;
}

//Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

//Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

//Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(0);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

//Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack->top;
    printf("Stack: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main function
int main() {
    Stack* stack = createStack();
    int choice, data;

    while (true) {
        printf("1. Push\n2. Pop\n3. Print stack\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                printf("Popped element: %d\n", data);
                break;
            case 3:
                printStack(stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}