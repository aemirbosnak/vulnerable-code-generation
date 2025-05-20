//Falcon-180B DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data;
    struct node *next;
};

struct stack {
    struct node *top;
};

struct stack *create_stack() {
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->top = NULL;
    return stack;
}

int is_empty(struct stack *stack) {
    return (stack->top == NULL);
}

void push(struct stack *stack, char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

char pop(struct stack *stack) {
    char data;
    if (is_empty(stack)) {
        printf("Stack is empty!\n");
        return '\0';
    } else {
        struct node *temp = stack->top;
        data = temp->data;
        stack->top = temp->next;
        free(temp);
        return data;
    }
}

void print_stack(struct stack *stack) {
    struct node *temp = stack->top;
    printf("Stack: ");
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct stack *stack = create_stack();
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Print\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(stack, (char)data);
                break;
            case 2:
                data = pop(stack);
                if (data!= '\0') {
                    printf("Popped data: %c\n", data);
                }
                break;
            case 3:
                print_stack(stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}