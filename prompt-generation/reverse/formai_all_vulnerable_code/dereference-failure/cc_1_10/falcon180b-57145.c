//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_SIZE 100

typedef struct node{
    char data;
    struct node* next;
}Node;

typedef struct stack{
    Node* top;
}Stack;

Stack* create_stack(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    if(stack==NULL){
        printf("Stack creation failed due to insufficient memory.\n");
        exit(0);
    }
    stack->top=NULL;
    return stack;
}

void push(Stack* stack, char data){
    Node* new_node=(Node*)malloc(sizeof(Node));
    if(new_node==NULL){
        printf("Stack push operation failed due to insufficient memory.\n");
        exit(0);
    }
    new_node->data=data;
    new_node->next=stack->top;
    stack->top=new_node;
}

char pop(Stack* stack){
    if(stack->top==NULL){
        printf("Stack is empty.\n");
        exit(0);
    }
    char data=stack->top->data;
    Node* temp=stack->top;
    stack->top=stack->top->next;
    free(temp);
    return data;
}

int is_empty(Stack* stack){
    if(stack->top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(Stack* stack){
    if(stack->top==NULL){
        return 0;
    }
    else{
        return 1;
    }
}

void print_stack(Stack* stack){
    if(is_empty(stack)){
        printf("Stack is empty.\n");
    }
    else{
        Node* temp=stack->top;
        while(temp!=NULL){
            printf("%c ", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    Stack* stack=create_stack();
    push(stack, 'a');
    push(stack, 'b');
    push(stack, 'c');
    print_stack(stack);
    pop(stack);
    pop(stack);
    print_stack(stack);
    return 0;
}