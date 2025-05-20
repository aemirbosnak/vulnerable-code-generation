//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node *next;
} Node;

// Stack structure definition
typedef struct stack {
    Node *top;
} Stack;

// Stack initialization function
void init(Stack *s) {
    s->top = NULL;
}

// Push function to add a node to the top of the stack
void push(Stack *s, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop function to remove the top node from the stack
void pop(Stack *s) {
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
}

// Display function to print the stack elements
void display(Stack s) {
    Node *temp = s.top;
    printf("Stack elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(stack);

    pop(&stack);

    display(stack);

    pop(&stack);

    display(stack);

    pop(&stack);

    return 0;
}