//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int top;
} Stack;

void push(Stack* stack, Item item) {
    if (stack->top >= MAX_ITEMS) {
        printf("Stack is full.\n");
        return;
    }
    stack->items[stack->top] = item;
    stack->top++;
}

Item pop(Stack* stack) {
    if (stack->top <= 0) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[--stack->top];
}

void display_stack(Stack stack) {
    printf("Stack contents:\n");
    for (int i = 0; i < stack.top; i++) {
        printf("%s: %d\n", stack.items[i].name, stack.items[i].quantity);
    }
}

void add_item(Stack* stack, const char* name, int quantity) {
    Item item = {name, quantity};
    push(stack, item);
}

void remove_item(Stack* stack, const char* name) {
    Item current_item;
    while ((current_item = pop(stack)).quantity > 0) {
        if (strcmp(current_item.name, name) == 0) {
            printf("%s removed.\n", name);
            break;
        }
    }
    if (current_item.quantity == 0) {
        printf("%s not found.\n", name);
    }
}

void main() {
    Stack inventory;
    inventory.top = -1;

    add_item(&inventory, "Apples", 10);
    add_item(&inventory, "Bananas", 5);
    add_item(&inventory, "Oranges", 8);

    printf("Initial inventory:\n");
    display_stack(inventory);

    remove_item(&inventory, "Bananas");

    printf("\nInventory after removing Bananas:\n");
    display_stack(inventory);
}