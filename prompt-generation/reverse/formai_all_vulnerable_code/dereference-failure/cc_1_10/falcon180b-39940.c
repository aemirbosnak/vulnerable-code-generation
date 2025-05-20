//Falcon-180B DATASET v1.0 Category: Educational ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;

void push(int value){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    printf("%d pushed into the stack\n",value);
}

void pop(){
    if(head==NULL){
        printf("Stack is empty\n");
    }
    else{
        struct node* temp=head;
        head=head->next;
        free(temp);
        printf("%d popped from the stack\n",temp->data);
    }
}

void display(){
    struct node* temp=head;
    if(head==NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are:\n");
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

int peek(){
    if(head==NULL){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return head->data;
    }
}

int is_empty(){
    return (head==NULL);
}

int is_full(){
    struct node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(count==MAX){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int choice,value;
    do{
        printf("\nEnter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Check if the stack is empty\n");
        printf("6. Check if the stack is full\n");
        printf("7. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the value to be pushed:\n");
                scanf("%d",&value);
                push(value);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                value=peek();
                if(value!=-1){
                    printf("Top element is %d\n",value);
                }
                else{
                    printf("Stack is empty\n");
                }
                break;
            }
            case 5:{
                if(is_empty()){
                    printf("Stack is empty\n");
                }
                else{
                    printf("Stack is not empty\n");
                }
                break;
            }
            case 6:{
                if(is_full()){
                    printf("Stack is full\n");
                }
                else{
                    printf("Stack is not full\n");
                }
                break;
            }
            case 7:{
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }while(choice!=7);
    return 0;
}