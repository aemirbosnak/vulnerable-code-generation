//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

void printStack(Stack* s) {
    Node* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    s.top = NULL;

    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    push(&s, 20);
    push(&s, 25);

    printStack(&s);

    printf("Popped element: %d\n", pop(&s));

    printStack(&s);

    return 0;
}