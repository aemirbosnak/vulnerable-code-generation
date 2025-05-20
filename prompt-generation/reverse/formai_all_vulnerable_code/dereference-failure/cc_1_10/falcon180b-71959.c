//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void enqueue(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else if(rear!=NULL){
        rear->next=newnode;
        rear=newnode;
    }
    else{
        front=newnode;
        rear=newnode;
    }
}

void dequeue(){
    if(front==NULL && rear==NULL){
        printf("\nQueue is Empty");
    }
    else if(front!=NULL){
        printf("\nElement Dequeued: %d",front->data);
        node *temp=front;
        front=front->next;
        free(temp);
    }
    else{
        printf("\nQueue is Empty");
    }
}

void display(){
    if(front==NULL && rear==NULL){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nQueue Elements are: ");
        node *temp=front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    int choice,data;
    do{
        printf("\n\nMENU");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the element to be enqueued: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice!");
        }
    }while(choice!=4);
    return 0;
}