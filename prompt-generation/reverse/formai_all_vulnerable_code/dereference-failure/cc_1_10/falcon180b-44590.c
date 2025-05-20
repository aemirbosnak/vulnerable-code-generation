//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

void init_stack(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

int is_empty(Stack* s) {
    return s->size == 0;
}

void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

int peek(Stack* s) {
    if (is_empty(s)) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    return s->top->data;
}

void print_stack(Stack* s) {
    if (is_empty(s)) {
        printf("Empty stack\n");
        return;
    }
    printf("Stack: ");
    Node* curr = s->top;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    print_stack(&s);

    int popped = pop(&s);
    printf("Popped element: %d\n", popped);

    print_stack(&s);

    int peeked = peek(&s);
    printf("Peeked element: %d\n", peeked);

    return 0;
}