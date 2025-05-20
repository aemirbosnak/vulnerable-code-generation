//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

void push(Stack *stack, int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->head;
    stack->head = newNode;
    stack->size++;
}

int pop(Stack *stack) {
    int value = stack->head->value;
    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;
    return value;
}

void printStack(Stack *stack) {
    Node *current = stack->head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.head = NULL;
    stack.size = 0;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printStack(&stack);
    printf("Popped: %d\n", pop(&stack));
    printStack(&stack);

    return 0;
}