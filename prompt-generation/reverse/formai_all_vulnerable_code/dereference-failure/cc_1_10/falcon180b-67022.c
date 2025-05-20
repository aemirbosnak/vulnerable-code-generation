//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

//Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

//Stack structure using linked list
typedef struct {
    Node *top;
} Stack;

//Function to create a new node
Node* createNode(char data[]) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->data, data);
    newnode->next = NULL;
    return newnode;
}

//Function to push a node onto the stack
void push(Stack *stack, char data[]) {
    Node *newnode = createNode(data);
    newnode->next = stack->top;
    stack->top = newnode;
}

//Function to pop a node from the stack
Node* pop(Stack *stack) {
    Node *temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

//Function to check if the stack is empty
int isEmpty(Stack stack) {
    return (stack.top == NULL);
}

//Function to print the stack
void printStack(Stack stack) {
    Node *temp = stack.top;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    //Test push function
    push(&stack, "Hello");
    push(&stack, "World");

    //Test print function
    printStack(stack);

    //Test pop function
    Node *popped = pop(&stack);
    printf("Popped element: %s\n", popped->data);

    //Test print function again
    printStack(stack);

    return 0;
}