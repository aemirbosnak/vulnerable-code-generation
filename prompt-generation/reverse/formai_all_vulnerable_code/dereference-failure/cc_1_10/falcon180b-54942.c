//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack* s) {
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

int peek(Stack* s) {
    return s->top->data;
}

int is_empty(Stack* s) {
    return s->top == NULL;
}

void print_stack(Stack* s) {
    Node* current = s->top;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Stack s;
    s.top = NULL;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("Stack: ");
    print_stack(&s);

    int popped_data = pop(&s);
    printf("Popped data: %d\n", popped_data);

    printf("Stack: ");
    print_stack(&s);

    int peeked_data = peek(&s);
    printf("Peeked data: %d\n", peeked_data);

    return 0;
}