//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
    int size;
};

void push(struct stack* S, int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = S->top;
    S->top = temp;
    S->size++;
}

int pop(struct stack* S) {
    if (S->size == 0) {
        printf("Stack underflow!\n");
        return -1;
    }
    struct node* temp = S->top;
    int data = temp->data;
    S->top = S->top->next;
    free(temp);
    S->size--;
    return data;
}

void display_stack(struct stack* S) {
    if (S->size == 0) {
        printf("Stack is empty!\n");
        return;
    }
    struct node* temp = S->top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct stack S;
    S.top = NULL;
    S.size = 0;

    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    display_stack(&S);

    int data = pop(&S);
    printf("Popped element: %d\n", data);
    display_stack(&S);

    push(&S, 5);
    push(&S, 6);
    display_stack(&S);
    return 0;
}