//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure
struct node {
    int data;
    struct node* next;
};

// Define a stack structure
struct stack {
    struct node* top;
};

// Initialize an empty stack
void init(struct stack* s) {
    s->top = NULL;
}

// Check if the stack is empty
bool is_empty(struct stack* s) {
    if (s->top == NULL) {
        return true;
    } else {
        return false;
    }
}

// Push a node onto the stack
void push(struct stack* s, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop a node from the stack
int pop(struct stack* s) {
    struct node* temp_node = s->top;
    int data = temp_node->data;
    s->top = temp_node->next;
    free(temp_node);
    return data;
}

// Print the stack
void print(struct stack* s) {
    struct node* temp_node = s->top;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    print(&s);

    int popped_data = pop(&s);
    printf("Popped data: %d\n", popped_data);

    print(&s);

    return 0;
}