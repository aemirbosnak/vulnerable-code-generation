//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *input;
    char *output;
} Stack;

void push(Stack *stack, char *value) {
    stack->input = realloc(stack->input, strlen(stack->input) + strlen(value) + 1);
    strcat(stack->input, value);
}

char *pop(Stack *stack) {
    char *result = stack->input;
    stack->input = NULL;
    return result;
}

int is_binary(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (str[i]!= '0' && str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    Stack stack;

    printf("Enter a binary number: ");
    fgets(input, MAX_SIZE, stdin);

    stack.input = input;
    stack.output = output;

    int i = 0;
    while (stack.input[i]!= '\0') {
        if (is_binary(stack.input)) {
            push(&stack, stack.input);
            i += strlen(stack.input);
            stack.input = &stack.input[i];
        } else {
            printf("Invalid input. Please enter a binary number.\n");
            return 1;
        }
    }

    if (stack.output[0] == '\0') {
        printf("Invalid input. Please enter a binary number.\n");
        return 1;
    }

    printf("Decimal equivalent: %s\n", pop(&stack));

    return 0;
}