//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define MAX_SIZE 10000

typedef struct {
    int data;
    int height;
    int width;
    struct node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

void init_stack(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

int is_empty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->height = 1;
    new_node->width = 1;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    Node* temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;
    return data;
}

void print_stack(Stack* s) {
    Node* curr = s->top;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    print_stack(&s);

    int data = pop(&s);
    printf("Popped element is %d\n", data);

    print_stack(&s);

    return 0;
}