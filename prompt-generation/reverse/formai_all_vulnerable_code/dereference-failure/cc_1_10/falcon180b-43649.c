//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack->top;
    printf("Stack elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Create a stack of size 5
    Stack stack;
    stack.top = NULL;

    // Push elements onto the stack
    for (int i = 0; i < 5; i++) {
        int data = rand() % 100;
        push(&stack, data);
    }

    // Display the elements in the stack
    printf("Initial stack: ");
    display(&stack);

    // Pop an element from the stack
    int popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    // Display the elements in the stack after popping an element
    printf("Stack after popping an element: ");
    display(&stack);

    return 0;
}