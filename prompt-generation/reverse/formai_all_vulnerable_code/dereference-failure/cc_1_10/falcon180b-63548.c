//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void push(Node** top_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(Node** top_ref) {
    char res;
    Node* top = *top_ref;
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(0);
    }
    res = top->data;
    Node* temp = top;
    *top_ref = top->next;
    free(temp);
    return res;
}

int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    return top->data;
}

void printStack(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    printf("Stack elements are: ");
    while (top!= NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
}

int main() {
    Node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    printStack(top);
    printf("\nAfter popping an element from stack: ");
    pop(&top);
    printStack(top);
    printf("\nTop element is: %d\n", peek(top));
    return 0;
}