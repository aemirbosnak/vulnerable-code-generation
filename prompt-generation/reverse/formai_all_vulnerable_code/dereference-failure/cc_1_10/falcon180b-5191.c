//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked List structure
typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

// Stack structure
typedef struct stack {
    LinkedList* list;
} Stack;

// Initialize an empty Linked List
LinkedList* create_linked_list() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Initialize an empty Stack
Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->list = create_linked_list();
    return stack;
}

// Push a node onto the Stack
void push(Stack* stack, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    stack->list->head = node;
    stack->list->size++;
}

// Pop a node from the Stack
int pop(Stack* stack) {
    if (stack->list->head == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    Node* node = stack->list->head;
    int data = node->data;
    stack->list->head = node->next;
    free(node);
    stack->list->size--;
    return data;
}

// Print the Stack
void print_stack(Stack* stack) {
    if (stack->list->head == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node* node = stack->list->head;
    printf("Stack:");
    while (node!= NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_stack(stack);
    int popped = pop(stack);
    printf("Popped: %d\n", popped);
    print_stack(stack);
    return 0;
}