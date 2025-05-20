//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int main() {
    Stack* s = createStack();
    push(s, 5);
    push(s, 10);
    push(s, 15);

    printf("Top element is %d\n", peek(s));
    printf("Popped element is %d\n", pop(s));
    printf("Top element is %d\n", peek(s));
    printf("Popped element is %d\n", pop(s));
    printf("Top element is %d\n", peek(s));

    return 0;
}