//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

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

void push(Stack* s, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Error: Stack underflow\n");
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
    if (s->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    return s->top->data;
}

int is_empty(Stack* s) {
    return s->top == NULL;
}

int is_full(Stack* s) {
    return s->size == MAX_SIZE;
}

void print_stack(Stack* s) {
    if (is_empty(s)) {
        printf("Empty stack\n");
        return;
    }
    Node* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    init_stack(&s);

    for (int i = 0; i < MAX_SIZE; i++) {
        push(&s, i);
    }

    print_stack(&s);

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("Popped: %d\n", pop(&s));
    }

    print_stack(&s);

    return 0;
}