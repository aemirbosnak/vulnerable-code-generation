//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

Stack* create_stack() {
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    if (new_stack == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_stack->top = NULL;
    return new_stack;
}

void push(Stack* stack, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(Stack* stack) {
    if (stack->top == NULL)
        return -1;
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void display(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = create_stack();
    int choice, data;

    do {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data!= -1)
                    printf("Popped data: %d\n", data);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}