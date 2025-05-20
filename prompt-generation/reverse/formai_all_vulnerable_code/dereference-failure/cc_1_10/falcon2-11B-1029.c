//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        return -1; // Stack is empty
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to display the elements of the stack
void display(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Pushing elements onto the stack
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    // Displaying the stack
    display(&stack);

    // Popping elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    display(&stack);

    return 0;
}