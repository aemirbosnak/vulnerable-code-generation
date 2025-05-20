//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *top;
};

void push(struct stack *S, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = S->top;
    S->top = new_node;
}

int pop(struct stack *S) {
    int value;
    if(S->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    } else {
        struct node *temp = S->top;
        value = temp->data;
        S->top = temp->next;
        free(temp);
        return value;
    }
}

void display(struct stack *S) {
    if (S->top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct node *temp = S->top;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    struct stack S;
    S.top = NULL;
    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    printf("Stack after push operation:\n");
    display(&S);
    printf("Popped value: %d\n", pop(&S));
    printf("Stack after pop operation:\n");
    display(&S);
    return 0;
}