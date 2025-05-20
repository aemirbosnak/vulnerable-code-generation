//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAPACITY 10

typedef struct {
    int *array;
    size_t capacity;
    size_t size;
} Stack;

Stack *create_stack(size_t capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->array = (int *) malloc(capacity * sizeof(int));
    stack->capacity = capacity;
    stack->size = 0;
    return stack;
}

int is_empty(Stack *stack) {
    return stack->size == 0;
}

int is_full(Stack *stack) {
    return stack->size == stack->capacity;
}

void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack is full! Cannot add any more elements.\n");
        return;
    }
    stack->array[stack->size++] = value;
    printf("Element added successfully!\n");
}

void pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty! Cannot remove any elements.\n");
        return;
    }
    stack->size--;
    printf("Element removed successfully!\n");
}

void display_stack(Stack *stack) {
    printf("Top -> ");
    for (int i = stack->size - 1; i >= 0; i--)
        printf("%d -> ", stack->array[i]);
    printf("NULL\n");
}

int main() {
    srand(time(NULL));
    Stack *stack = create_stack(MAX_CAPACITY);
    printf("Stack created successfully!\n\n");

    for (int i = 0; i < 5; i++) {
        int value = rand() % 100;
        printf("Adding element %d to the stack.\n", value);
        push(stack, value);
        display_stack(stack);
        printf("\n");
    }

    for (int i = 0; i < 5; i++) {
        printf("Removing top element from the stack.\n");
        pop(stack);
        display_stack(stack);
        printf("\n");
    }

    printf("Adding %d more elements to the stack.\n\n", MAX_CAPACITY - stack->size);
    for (int i = stack->size; i < MAX_CAPACITY; i++) {
        int value = rand() % 100;
        printf("Adding element %d to the stack.\n", value);
        push(stack, value);
        display_stack(stack);
        printf("\n");
    }

    printf("Trying to add more elements to the stack.\n");
    push(stack, rand() % 100);

    free(stack->array);
    free(stack);

    return 0;
}