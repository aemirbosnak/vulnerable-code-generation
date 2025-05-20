//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the structure of the node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the linked list
typedef struct list {
    Node* head;
} List;

// Define the structure of the stack
typedef struct stack {
    List* list;
    pthread_mutex_t lock;
} Stack;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new linked list
List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

// Function to create a new stack
Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->list = create_list();
    pthread_mutex_init(&stack->lock, NULL);
    return stack;
}

// Function to push a node onto the stack
void push(Stack* stack, int data) {
    Node* node = create_node(data);
    pthread_mutex_lock(&stack->lock);
    node->next = stack->list->head;
    stack->list->head = node;
    pthread_mutex_unlock(&stack->lock);
}

// Function to pop a node from the stack
Node* pop(Stack* stack) {
    Node* node = NULL;
    pthread_mutex_lock(&stack->lock);
    if (stack->list->head!= NULL) {
        node = stack->list->head;
        stack->list->head = node->next;
    }
    pthread_mutex_unlock(&stack->lock);
    return node;
}

// Function to print the stack
void print_stack(Stack* stack) {
    Node* node = stack->list->head;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to destroy the stack
void destroy_stack(Stack* stack) {
    while (stack->list->head!= NULL) {
        Node* node = pop(stack);
        free(node);
    }
    pthread_mutex_destroy(&stack->lock);
    free(stack->list);
    free(stack);
}

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_stack(stack);
    Node* node = pop(stack);
    printf("Popped node: %d\n", node->data);
    print_stack(stack);
    destroy_stack(stack);
    return 0;
}