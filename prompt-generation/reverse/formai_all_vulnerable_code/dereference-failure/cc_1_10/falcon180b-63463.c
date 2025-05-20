//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node in a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for a stack
typedef struct Stack {
    Node* top;
    int size;
} Stack;

// Initialize an empty stack
void init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

// Check if the stack is empty
bool is_empty(Stack* s) {
    return s->top == NULL;
}

// Get the size of the stack
int size(Stack* s) {
    return s->size;
}

// Push an element onto the stack
void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = s->top;
    int data = s->top->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

// Display the elements in the stack
void display(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = s->top;
    printf("Stack elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    pop(&s);
    display(&s);
    pop(&s);
    display(&s);
    pop(&s);
    display(&s);
    return 0;
}