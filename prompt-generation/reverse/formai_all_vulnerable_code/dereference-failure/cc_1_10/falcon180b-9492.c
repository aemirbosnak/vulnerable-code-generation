//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct node* front=NULL,*rear=NULL;

void enqueue(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    if(front==NULL && rear==NULL){
        front=new_node;
        rear=new_node;
    }
    else if(rear==NULL){
        rear=new_node;
        new_node->next=front;
        front->next=NULL;
    }
    else{
        rear->next=new_node;
        new_node->next=front;
        rear=rear->next;
    }
    printf("%d enqueued to the queue\n",data);
}

void dequeue(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("%d dequeued from the queue\n",front->data);
    struct node* temp=front;
    front=front->next;
    free(temp);
    if(front==NULL){
        rear=NULL;
    }
}

void display(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    struct node* temp=front;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=front);
    printf("\n");
}

int main(){
    int choice,data;
    while(true){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to enqueue: ");
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
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}