//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
    int size;
} Stack;

Stack *create_stack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

int is_empty(Stack *s) {
    return s->top == NULL;
}

int is_full(Stack *s) {
    return s->size == MAX_SIZE;
}

void push(Stack *s, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    Node *temp = s->top;
    s->top = s->top->next;
    s->size--;
    int data = temp->data;
    free(temp);
    return data;
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->top->data;
}

void print_stack(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    Node *temp = s->top;
    printf("Stack: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack *s = create_stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    print_stack(s);
    printf("Top element is: %d\n", peek(s));
    printf("Popped element is: %d\n", pop(s));
    print_stack(s);
    printf("Top element is: %d\n", peek(s));
    printf("Popped element is: %d\n", pop(s));
    print_stack(s);
    free(s);
    return 0;
}