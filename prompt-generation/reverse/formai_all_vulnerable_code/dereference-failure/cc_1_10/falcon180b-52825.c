//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Node structure
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//Stack structure
typedef struct Stack{
    Node* top;
}Stack;

//Stack functions
Stack* create_stack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack* s){
    Node* temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

int peek(Stack* s){
    return s->top->data;
}

bool is_empty(Stack* s){
    return s->top == NULL;
}

//Linked List functions
void traverse(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int length(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
    Stack* s1 = create_stack();
    push(s1, 10);
    push(s1, 20);
    push(s1, 30);
    int popped = pop(s1);
    printf("Popped element: %d\n", popped);
    printf("Top element: %d\n", peek(s1));
    traverse(s1->top);
    printf("Length of stack: %d\n", length(s1->top));
    printf("Is stack empty? %s\n", is_empty(s1)? "Yes" : "No");
    return 0;
}