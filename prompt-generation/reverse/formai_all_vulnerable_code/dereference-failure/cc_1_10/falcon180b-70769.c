//Falcon-180B DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int size;
    struct Node* next;
} Node;

void push(Node** top_ref, int new_data);
Node* pop(Node** top_ref);
int peek(Node* top);
void printStack(Node* top);

int main() {
    Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack: ");
    printStack(stack);

    Node* popped_node = pop(&stack);
    printf("\nPopped element is %d\n", popped_node->data);

    printf("Stack after popping an element: ");
    printStack(stack);

    return 0;
}

void push(Node** top_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Stack overflow \n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->size = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

Node* pop(Node** top_ref) {
    Node* top = *top_ref;

    if (top == NULL) {
        printf("Stack underflow \n");
        exit(0);
    }

    Node* temp = top;
    top = top->next;
    free(temp);

    return top;
}

int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty \n");
        exit(0);
    }

    return top->data;
}

void printStack(Node* top) {
    if (top == NULL) {
        printf("Stack is empty \n");
        exit(0);
    }

    printf("Stack elements are: ");

    while (top!= NULL) {
        printf("%d ", top->data);
        top = top->next;
    }

    printf("\n");
}