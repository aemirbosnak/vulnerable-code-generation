//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node *next;
};

struct node *start = NULL;

void push(char data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(start == NULL){
        start = newnode;
    }
    else{
        struct node *temp = start;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void pop(){
    if(start == NULL){
        printf("Stack is empty");
    }
    else{
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
}

void display(){
    if(start == NULL){
        printf("Stack is empty");
    }
    else{
        struct node *temp = start;
        while(temp!= NULL){
            printf("%c",temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int choice,data;
    char ch;
    do{
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push(ch);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice");
        }
    }while(choice!= 4);
    return 0;
}