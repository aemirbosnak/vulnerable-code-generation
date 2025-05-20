//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of the node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the stack
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Initialize the stack with the given maximum size
void init(Stack* s, int max_size) {
    s->top = NULL;
    s->size = 0;
}

// Check if the stack is empty
bool is_empty(Stack* s) {
    return s->top == NULL;
}

// Check if the stack is full
bool is_full(Stack* s) {
    return s->size == MAX_SIZE;
}

// Push an element onto the stack
void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    int data = s->top->data;
    Node* temp_node = s->top;
    s->top = s->top->next;
    free(temp_node);
    s->size--;
    return data;
}

// Display the elements in the stack
void display(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack:\n");
    Node* temp_node = s->top;
    while (temp_node!= NULL) {
        printf("%d\n", temp_node->data);
        temp_node = temp_node->next;
    }
}

// Main function
int main() {
    Stack s;
    init(&s, MAX_SIZE);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    display(&s);
    pop(&s);
    display(&s);
    pop(&s);
    display(&s);
    pop(&s);
    display(&s);
    pop(&s);
    display(&s);
    pop(&s);
    return 0;
}