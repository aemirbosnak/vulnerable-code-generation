//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct stack{
    Node* top;
    int size;
}Stack;

void init(Stack* stack){
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(Stack* stack){
    if(stack->top == NULL){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack* stack){
    if(stack->size == MAX_SIZE){
        return 1;
    }else{
        return 0;
    }
}

void push(Stack* stack, int data){
    if(isFull(stack)){
        printf("Stack Overflow\n");
        return;
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        printf("Memory Error\n");
        return;
    }
    temp->data = data;
    temp->next = stack->top;
    stack->top = temp;
    stack->size++;
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

void display(Stack* stack){
    Node* temp = stack->top;
    printf("Stack elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Stack stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);
    printf("Top element is: %d\n", peek(&stack));
    int data = pop(&stack);
    printf("Popped element is: %d\n", data);
    display(&stack);
    return 0;
}