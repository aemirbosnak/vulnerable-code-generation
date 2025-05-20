//FormAI DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
};

void push(struct stack* ptr, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = ptr->top;
    ptr->top = newNode;
    printf("Pushed %d to stack\n", value);
}

void pop(struct stack* ptr) {
    if (ptr->top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    struct node* temp = ptr->top;
    ptr->top = ptr->top->next;
    printf("Popped %d from stack\n", temp->data);
    free(temp);
}

void display(struct stack* ptr) {
    if (ptr->top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    struct node* temp = ptr->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    struct stack st = {NULL};

    for (int i = 0; i < 5; i++) {
        push(&st, rand()%100);
    }
    printf("\nCurrent Stack: ");
    display(&st);

    printf("\nPerforming Pop Operations:\n");
    for (int i = 0; i < 3; i++) {
        pop(&st);
    }
    printf("\nCurrent Stack: ");
    display(&st);

    printf("\nPushing 2 more random numbers to the Stack\n");
    for (int i = 0; i < 2; i++) {
        push(&st, rand()%100);
    }
    printf("\nCurrent Stack: ");
    display(&st);

    printf("\nPerforming Pop Operations:\n");
    for (int i = 0; i < 4; i++) {
        pop(&st);
    }
    printf("\nCurrent Stack: ");
    display(&st);

    return 0;
}