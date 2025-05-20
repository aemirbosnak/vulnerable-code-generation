//FormAI DATASET v1.0 Category: Data structures visualization ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10

typedef struct node {
    int data;
    struct node* next;
} Node;

int* create_array(int size) {
    int* arr = (int*) malloc(sizeof(int) * size);
    memset(arr, 0, sizeof(int) * size);
    return arr;
}

void print_array(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Node** headRef, int data) {
    Node* newNode = create_node(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

int pop(Node** headRef) {
    int data = (*headRef)->data;
    Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
    return data;
}

void print_list(Node* head) {
    printf("[");
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(", ");
        head = head->next;
    }
    printf("]\n");
}

int main() {
    int* arr = create_array(ARRAY_SIZE);
    printf("Created an array of size %d: ", ARRAY_SIZE);
    print_array(arr, ARRAY_SIZE);

    printf("Pushing values onto a stack...\n");
    Node* stack = NULL;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("Stack after pushing: ");
    print_list(stack);

    printf("Popping values from the stack...\n");
    printf("Popped value: %d\n", pop(&stack));
    printf("Popped value: %d\n", pop(&stack));
    printf("Stack after popping: ");
    print_list(stack);

    return 0;
}