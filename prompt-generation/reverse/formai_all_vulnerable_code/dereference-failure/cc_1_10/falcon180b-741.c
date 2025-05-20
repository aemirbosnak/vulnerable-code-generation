//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

void stack_init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

bool stack_is_empty(Stack* s) {
    return s->size == 0;
}

void stack_push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

int stack_pop(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    Node* temp_node = s->top;
    int data = temp_node->data;
    s->top = temp_node->next;
    free(temp_node);
    s->size--;
    return data;
}

int stack_peek(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->top->data;
}

void stack_display(Stack* s) {
    printf("Stack: ");
    Node* temp_node = s->top;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

void stack_destroy(Stack* s) {
    while (!stack_is_empty(s)) {
        stack_pop(s);
    }
    free(s);
}

int main() {
    Stack s;
    stack_init(&s);

    stack_push(&s, 1);
    stack_push(&s, 2);
    stack_push(&s, 3);

    stack_display(&s);

    int popped_data = stack_pop(&s);
    printf("Popped data: %d\n", popped_data);

    stack_display(&s);

    int peeked_data = stack_peek(&s);
    printf("Peeked data: %d\n", peeked_data);

    stack_destroy(&s);

    return 0;
}