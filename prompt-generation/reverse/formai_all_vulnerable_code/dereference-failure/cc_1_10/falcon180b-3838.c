//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
}Stack;

void push(Stack *s, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    if(s->top == NULL){
        s->top = newnode;
    }
    else{
        newnode->next = s->top;
        s->top = newnode;
    }
}

int pop(Stack *s){
    int data = 0;
    Node *temp = s->top;

    if(s->top == NULL){
        printf("Stack Underflow\n");
        exit(0);
    }
    else{
        data = s->top->data;
        s->top = s->top->next;
        free(temp);
    }

    return data;
}

int peek(Stack *s){
    int data = 0;
    Node *temp = s->top;

    if(s->top == NULL){
        printf("Stack Underflow\n");
        exit(0);
    }
    else{
        data = s->top->data;
    }

    return data;
}

void display(Stack *s){
    Node *temp = s->top;

    if(s->top == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are:\n");
        while(temp!= NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    Stack s;
    s.top = NULL;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("Elements in Stack after pushing 10, 20, 30 and 40\n");
    display(&s);

    int x = pop(&s);
    printf("Element popped from Stack: %d\n", x);

    printf("Elements in Stack after popping an element\n");
    display(&s);

    int y = peek(&s);
    printf("Top element of Stack: %d\n", y);

    return 0;
}