//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

// Define a structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a structure for a stack
typedef struct stack {
    Node* top;
} Stack;

// Initialize an empty stack
void init_stack(Stack* s) {
    s->top = NULL;
}

// Push an element onto the stack
void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        return -1;
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Check if the stack is empty
int is_empty(Stack* s) {
    return s->top == NULL;
}

// Print the stack
void print_stack(Stack* s) {
    Node* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse the stack
void reverse_stack(Stack* s) {
    Node* prev = NULL;
    Node* curr = s->top;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    s->top = prev;
}

int main() {
    Stack s;
    init_stack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    print_stack(&s);
    reverse_stack(&s);
    print_stack(&s);
    return 0;
}