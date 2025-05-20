//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

//Node structure definition
struct Node{
    int data;
    struct Node* next;
};

//Stack structure definition using linked list
struct Stack{
    struct Node* top;
};

//Stack initialization
void init(struct Stack* stack) {
    stack->top = NULL;
}

//Stack push operation
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

//Stack pop operation
int pop(struct Stack* stack) {
    if(stack->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

//Stack display operation
void display(struct Stack stack) {
    struct Node* temp = stack.top;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//Main function
int main() {
    struct Stack stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    display(stack);
    printf("\n");
    int poppedValue = pop(&stack);
    printf("Popped value: %d\n", poppedValue);
    display(stack);
    return 0;
}