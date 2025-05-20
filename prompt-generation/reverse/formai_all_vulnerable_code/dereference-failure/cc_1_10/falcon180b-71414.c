//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

void push(struct node** top_ref, int new_data);
int pop(struct node** top_ref);
int peek(struct node* top);
void display(struct node* node);

int main() {
    struct node* top = NULL;

    // Test push operation
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    // Test pop operation
    printf("Popped element is: %d\n", pop(&top));

    // Test peek operation
    printf("Top element is: %d\n", peek(top));

    // Test display operation
    printf("Stack elements are: ");
    display(top);

    return 0;
}

// This function pushes an integer onto the stack
void push(struct node** top_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    if(new_node == NULL) {
        printf("Stack Overflow\n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

// This function pops an integer from the stack
int pop(struct node** top_ref) {
    char res;
    struct node* top = *top_ref;

    if(top == NULL) {
        printf("Stack Underflow\n");
        exit(0);
    }

    res = top->data;
    *top_ref = top->next;
    free(top);

    return res;
}

// This function returns the topmost element of the stack
int peek(struct node* top) {
    if(top == NULL) {
        printf("Stack is Empty\n");
        exit(0);
    }

    return top->data;
}

// This function displays all elements in the stack
void display(struct node* node) {
    while(node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}