//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX 100

// Node structure for linked list implementation of stack
struct node {
    int data;
    struct node* next;
};

// Stack structure
struct stack {
    struct node* top;
};

// Function to create an empty stack
void init(struct stack* s) {
    s->top = NULL;
}

// Function to push an integer onto the stack
void push(struct stack* s, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}

// Function to pop an integer from the stack
int pop(struct stack* s) {
    if(s->top == NULL) {
        printf("Stack underflow\n");
        exit(0);
    }
    int value = s->top->data;
    struct node* temp_node = s->top;
    s->top = s->top->next;
    free(temp_node);
    return value;
}

// Function to display the contents of the stack
void display(struct stack* s) {
    if(s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    struct node* temp_node = s->top;
    while(temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main() {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    init(stack);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    display(stack);

    int popped_value = pop(stack);
    printf("Popped value is: %d\n", popped_value);

    display(stack);

    return 0;
}