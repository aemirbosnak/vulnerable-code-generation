//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct Node** top_ref) {
    char res;
    struct Node* top = *top_ref;
    if (top == NULL)
        return -1;
    res = top->data;
    struct Node* temp = top;
    *top_ref = top->next;
    free(temp);
    return res;
}

void printStack(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    printStack(top);
    printf("\n");
    printf("Popped element is %d", pop(&top));
    printStack(top);
    printf("\n");
    return 0;
}