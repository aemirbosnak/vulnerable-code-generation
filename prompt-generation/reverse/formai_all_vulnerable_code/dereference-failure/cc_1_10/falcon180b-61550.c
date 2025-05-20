//Falcon-180B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

bool is_empty(char *stack, int top) {
    return top == -1;
}

bool is_full(char *stack, int top) {
    return top == MAX_SIZE - 1;
}

void push(char *stack, int *top, char element) {
    if (is_full(stack, *top)) {
        printf("Stack Overflow Error\n");
        exit(1);
    }
    *(stack + (*top)++) = element;
}

char pop(char *stack, int *top) {
    if (is_empty(stack, *top)) {
        printf("Stack Underflow Error\n");
        exit(1);
    }
    return *(stack + (*top)--);
}

void display(char *stack, int top) {
    if (is_empty(stack, top)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%c ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    char stack[MAX_SIZE];
    int top = -1;

    push(stack, &top, 'a');
    push(stack, &top, 'b');
    push(stack, &top, 'c');
    display(stack, top);

    char popped_element = pop(stack, &top);
    printf("Popped element is: %c\n", popped_element);
    display(stack, top);

    push(stack, &top, 'd');
    push(stack, &top, 'e');
    display(stack, top);

    return 0;
}