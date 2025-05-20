//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    node *top;
}stack;

void push(stack* s,int value){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    if(s->top == NULL){
        s->top = new_node;
    }
    else{
        new_node->next = s->top;
        s->top = new_node;
    }
}

int pop(stack* s){
    int value = 0;
    if(s->top!= NULL){
        value = s->top->data;
        node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    return value;
}

int peek(stack* s){
    int value = 0;
    if(s->top!= NULL){
        value = s->top->data;
    }
    return value;
}

int is_empty(stack* s){
    if(s->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void display_stack(stack* s){
    node* temp = s->top;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    stack s1,s2;
    s1.top = NULL;
    s2.top = NULL;

    push(&s1,1);
    push(&s1,2);
    push(&s1,3);
    push(&s1,4);
    push(&s1,5);

    push(&s2,6);
    push(&s2,7);
    push(&s2,8);
    push(&s2,9);
    push(&s2,10);

    printf("Stack 1: ");
    display_stack(&s1);

    printf("\nStack 2: ");
    display_stack(&s2);

    printf("\nTopmost element of Stack 1 is: %d",peek(&s1));

    printf("\nStack 1 after popping: ");
    pop(&s1);
    display_stack(&s1);

    printf("\nStack 2 after popping: ");
    pop(&s2);
    display_stack(&s2);

    printf("\nIs Stack 1 empty? %s",is_empty(&s1)?"Yes":"No");

    return 0;
}