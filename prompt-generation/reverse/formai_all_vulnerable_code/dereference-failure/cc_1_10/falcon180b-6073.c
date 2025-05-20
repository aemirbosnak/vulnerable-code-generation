//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure of a product
typedef struct {
    char name[50];
    int quantity;
    double price;
} Product;

// Define the structure of a stack
typedef struct {
    Product *array;
    int top;
    int capacity;
} Stack;

// Initialize an empty stack with a given capacity
void initStack(Stack *stack, int capacity) {
    stack->array = (Product *)malloc(capacity * sizeof(Product));
    stack->top = -1;
    stack->capacity = capacity;
}

// Free the memory used by a stack
void destroyStack(Stack *stack) {
    free(stack->array);
}

// Check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Push a product onto the stack
void push(Stack *stack, Product product) {
    if (isFull(stack)) {
        printf("Error: Stack is full.\n");
        return;
    }
    stack->array[++stack->top] = product;
}

// Pop a product from the stack
Product pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return (Product){0};
    }
    return stack->array[stack->top--];
}

// Display the current state of the stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current state of the stack:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%s - %d - $%.2f\n", stack->array[i].name, stack->array[i].quantity, stack->array[i].price);
    }
}

int main() {
    Stack stack;
    initStack(&stack, 10);

    push(&stack, (Product){"Apples", 5, 1.99});
    push(&stack, (Product){"Bananas", 3, 2.49});
    push(&stack, (Product){"Oranges", 7, 3.99});

    display(&stack);

    Product popped = pop(&stack);
    printf("Popped product: %s - %d - $%.2f\n", popped.name, popped.quantity, popped.price);

    destroyStack(&stack);
    return 0;
}