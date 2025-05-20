//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

Stack* create_stack() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

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

void print_stack(Stack* s) {
    Node* current = s->top;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* s = create_stack();
    push(s, 5);
    push(s, 10);
    push(s, 15);
    print_stack(s);

    int popped = pop(s);
    if (popped == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Popped element: %d\n", popped);
    }

    return 0;
}