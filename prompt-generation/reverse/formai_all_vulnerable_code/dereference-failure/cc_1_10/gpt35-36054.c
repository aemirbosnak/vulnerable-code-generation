//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node Definition
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Stack Definition
typedef struct Stack {
    Node* top;
    int size;
} Stack;

// Push() Function to add element to Stack
void push(Stack* s, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> val = val;
    new_node -> next = s -> top;
    s -> top = new_node;
    s -> size++;
    printf("%d pushed to Stack\n", val);
}

// Pop() Function to remove element from Stack
int pop(Stack* s) {
    if (s -> top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    int val = s -> top -> val;
    Node* temp = s -> top;
    s -> top = s -> top -> next;
    free(temp);
    s -> size--;
    return val;
}

// Display() Function to show the elements of Stack
void display(Stack* s) {
    if (s -> top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Elements in Stack are:\n");
    Node* curr = s -> top;
    while (curr != NULL) {
        printf("%d\n", curr -> val);
        curr = curr -> next;
    }
    printf("\n");
}

int main() {
    // Creating an empty Stack
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s -> top = NULL;
    s -> size = 0;

    push(s, 2);
    push(s, 4);
    push(s, 6);
    display(s);
    pop(s);
    display(s);

    return 0;
}