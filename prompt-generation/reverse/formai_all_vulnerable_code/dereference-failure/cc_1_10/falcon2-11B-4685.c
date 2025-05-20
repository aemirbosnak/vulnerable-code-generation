//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    struct Node* bottom;
};

void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (stack->bottom == NULL) {
        stack->top = newNode;
    } else {
        stack->bottom->next = newNode;
    }

    stack->bottom = newNode;
}

int pop(struct Stack* stack) {
    if (stack->bottom == NULL) {
        return -1;
    }

    int value = stack->bottom->value;
    struct Node* temp = stack->bottom->next;
    free(stack->bottom);
    stack->bottom = temp;

    if (stack->top == stack->bottom) {
        stack->top = NULL;
    }

    return value;
}

void print(struct Stack* stack) {
    if (stack->bottom == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* current = stack->bottom;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    stack.top = NULL;
    stack.bottom = NULL;

    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);
    push(&stack, 20);
    print(&stack);

    printf("Popped %d\n", pop(&stack));
    print(&stack);

    printf("Popped %d\n", pop(&stack));
    print(&stack);

    return 0;
}