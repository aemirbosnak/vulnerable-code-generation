//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure definition
struct node {
    char data[50];
    struct node* next;
};

// Stack structure definition using linked list
struct stack {
    struct node* top;
};

// Function to create a new node with given data
struct node* createNode(char data[50]) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty stack
struct stack* createStack() {
    struct stack* newStack = (struct stack*) malloc(sizeof(struct stack));
    if (newStack == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newStack->top = NULL;
    return newStack;
}

// Function to push an element onto the stack
void push(struct stack* stack, char data[50]) {
    struct node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
char* pop(struct stack* stack) {
    char data[50];
    struct node* temp = stack->top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    strcpy(data, temp->data);
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to display the current state of the stack
void display(struct stack* stack) {
    struct node* temp = stack->top;
    if (temp == NULL) {
        printf("Stack is empty\n");
    }
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse a string
char* reverseString(char str[50]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

int main() {
    struct stack* stack = createStack();
    char input[50];
    while (1) {
        printf("Enter a string: ");
        scanf("%s", input);
        push(stack, input);
    }
    return 0;
}