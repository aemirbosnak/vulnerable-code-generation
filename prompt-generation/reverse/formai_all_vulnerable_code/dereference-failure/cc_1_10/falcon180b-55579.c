//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* data;
    int size;
} Stack;

void initStack(Stack* stack) {
    stack->data = (char*)malloc(MAX_SIZE * sizeof(char));
    stack->size = 0;
}

void push(Stack* stack, char c) {
    if (stack->size >= MAX_SIZE) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->data[stack->size++] = c;
}

char pop(Stack* stack) {
    if (stack->size == 0) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->data[--stack->size];
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

void printStack(Stack* stack) {
    printf("[");
    for (int i = 0; i < stack->size; i++) {
        printf("%c", stack->data[i]);
    }
    printf("]\n");
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    printf("Stack: ");
    printStack(&stack);

    char searchChar;
    printf("Enter a character to search: ");
    scanf(" %c", &searchChar);

    int index = -1;
    for (int i = 0; i < stack.size; i++) {
        if (stack.data[i] == searchChar) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Character not found!\n");
    } else {
        printf("Character found at position %d!\n", index);
    }

    return 0;
}