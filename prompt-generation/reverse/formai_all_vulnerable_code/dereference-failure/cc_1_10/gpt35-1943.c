//FormAI DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    void* data;
    struct node* next;
    int size;
} node;

typedef struct stack {
    node* head;
    int count;
} stack;

stack* create_stack() {
    stack* new_stack = (stack*) malloc(sizeof(stack));
    new_stack->head = NULL;
    new_stack->count = 0;
    return new_stack;
}

void* allocate(stack* mem_stack, int size) {
    void* ptr = malloc(size);
    if (ptr) {
        node* new_node = (node*) malloc(sizeof(node));
        new_node->data = ptr;
        new_node->next = mem_stack->head;
        new_node->size = size;
        mem_stack->head = new_node;
        mem_stack->count++;
    }
    return ptr;
}

void release(stack* mem_stack) {
    if (mem_stack->head) {
        node* temp = mem_stack->head;
        mem_stack->head = mem_stack->head->next;
        free(temp->data);
        free(temp);
        mem_stack->count--;
    }
}

void release_all(stack* mem_stack) {
    while (mem_stack->count) {
        release(mem_stack);
    }
}

int main() {
    stack* mem_stack = create_stack();
    int* ptr1 = (int*) allocate(mem_stack, sizeof(int));
    *ptr1 = 5;
    char* ptr2 = (char*) allocate(mem_stack, MAX_SIZE);
    strcpy(ptr2, "This is an example of memory management using a stack.");
    printf("Integer: %d\nString: %s\n", *ptr1, ptr2);
    release(mem_stack);
    char* ptr3 = (char*) allocate(mem_stack, sizeof(char) * 10);
    strcpy(ptr3, "Goodbye!");
    printf("String: %s\n", ptr3);
    release_all(mem_stack);
    return 0;
}