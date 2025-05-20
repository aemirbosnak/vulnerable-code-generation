//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000

typedef struct {
    int top;
    int items[MAX_STACK_SIZE];
} stack;

stack* create_stack() {
    stack *s = (stack*)malloc(sizeof(stack));
    s->top = -1;

    return s;
}

int is_empty(stack* s) {
    return s->top == -1;
}

int is_full(stack* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(stack* s, int x) {
    if(is_full(s)) {
        printf("Stack Overflow!\n");
        return;
    }

    s->items[++s->top] = x;
}

int pop(stack* s) {
    if(is_empty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }

    return s->items[s->top--];
}

int main() {
    stack *luggage = create_stack();

    // Push luggage onto the stack
    push(luggage, 1);
    push(luggage, 2);
    push(luggage, 3);

    // Pop luggage from the stack and print the values
    printf("%d\n", pop(luggage));
    printf("%d\n", pop(luggage));
    printf("%d\n", pop(luggage));

    return 0;
}