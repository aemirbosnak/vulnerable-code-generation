//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;

    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    struct node *temp=front;
    front=front->next;

    if(front==NULL){
        rear=NULL;
    }

    free(temp);
}

void display(){
    struct node *temp=front;

    if(front==NULL){
        printf("\nQueue is empty");
        return;
    }

    printf("\nElements in the Queue are: ");

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main(){
    int choice,x;

    while(1){
        printf("\n\n********* MENU *********");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("\nEnter the element to be enqueued: ");
                     scanf("%d",&x);
                     enqueue(x);
                     break;

            case 2: dequeue();
                     break;

            case 3: display();
                     break;

            case 4: exit(0);

            default: printf("\nInvalid choice. Please enter again");
        }
    }
}