//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

typedef struct _stack {
    node *top;
} stack;

void push(stack *s, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    node *temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

void print_stack(stack *s) {
    node *temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    stack *source = (stack *)malloc(sizeof(stack));
    source->top = NULL;
    stack *destination = (stack *)malloc(sizeof(stack));
    destination->top = NULL;
    stack *auxiliary = (stack *)malloc(sizeof(stack));
    auxiliary->top = NULL;

    for (int i = n; i >= 1; i--) {
        push(source, i);
    }

    printf("Initial state:\n");
    print_stack(source);
    print_stack(destination);
    print_stack(auxiliary);

    int steps = (1 << n) - 1;
    for (int i = 1; i <= steps; i++) {
        if (i % 3 == 1) {
            int data = pop(source);
            push(destination, data);
        } else if (i % 3 == 2) {
            int data = pop(source);
            push(auxiliary, data);
        } else {
            int data = pop(auxiliary);
            push(destination, data);
        }

        printf("Step %d:\n", i);
        print_stack(source);
        print_stack(destination);
        print_stack(auxiliary);
    }

    printf("Final state:\n");
    print_stack(source);
    print_stack(destination);
    print_stack(auxiliary);

    return 0;
}