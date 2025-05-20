//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

void push(node** top_ref, int new_data);
int pop(node** top_ref);
int peek(node* top);
void printList(node* node);

int main() {
    node* top = NULL;

    push(&top, 50);
    push(&top, 40);
    push(&top, 70);
    push(&top, 60);
    push(&top, 80);

    printf("Stack elements are: ");
    printList(top);

    printf("\nAfter popping an element from the stack: ");
    pop(&top);
    printList(top);

    return 0;
}

void push(node** top_ref, int new_data) {
    node* new_node = (node*) malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Stack overflow \n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;

    printf("%d pushed to stack\n", new_data);
}

int pop(node** top_ref) {
    char res;
    node* top = *top_ref;

    if (top == NULL) {
        printf("Stack underflow \n");
        exit(0);
    }
    else {
        res = top->data;
        node* temp = top;
        top = top->next;
        free(temp);

        printf("%d popped from stack\n", res);
        return res;
    }
}

int peek(node* top) {
    if (top == NULL) {
        printf("Stack is Empty \n");
        exit(0);
    }
    else {
        return top->data;
    }
}

void printList(node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}