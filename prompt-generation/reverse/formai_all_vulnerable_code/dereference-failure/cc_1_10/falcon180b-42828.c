//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>

// Define a struct to represent a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a struct to represent a stack
typedef struct stack {
    Node* top;
} Stack;

// Define a function to initialize a stack
void init(Stack* s) {
    s->top = NULL;
}

// Define a function to push an element onto the stack
void push(Stack* s, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Define a function to pop an element from the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = s->top;
    int data = s->top->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Define a function to print the elements in the stack
void print(Stack* s) {
    Node* temp = s->top;
    printf("Stack: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Define a function to reverse a linked list
void reverse(Node** headRef) {
    Node* prev = NULL;
    Node* curr = *headRef;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *headRef = prev;
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    print(&s);
    reverse(&s.top);
    print(&s);
    int popped = pop(&s);
    printf("Popped: %d\n", popped);
    print(&s);
    return 0;
}