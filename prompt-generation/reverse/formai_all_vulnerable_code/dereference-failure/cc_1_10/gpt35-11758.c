//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createNode(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insert(struct node **head, int data){
    struct node *newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
    }
    else{
        struct node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void display(struct node **head){
    struct node *temp=*head;
    printf("Head -> ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node *head=NULL;
    printf("Inserting 10\n");
    insert(&head,10);
    display(&head);
    printf("\nInserting 20\n");
    insert(&head,20);
    display(&head);
    printf("\nInserting 30\n");
    insert(&head,30);
    display(&head);
    return 0;
}