//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Structure for queue node
struct node{
    int data;
    struct node *next;
};

// Function to enqueue an element
void enqueue(struct node **head_ref, int new_data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(*head_ref==NULL){
        (*head_ref)=newnode;
        newnode->data=new_data;
        newnode->next=NULL;
    }
    else{
        newnode->data=new_data;
        newnode->next=*head_ref;
        *head_ref=newnode;
    }
}

// Function to dequeue an element
int dequeue(struct node **head_ref){
    if(*head_ref==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int temp=(*head_ref)->data;
        struct node *tempnode=*head_ref;
        *head_ref=(*head_ref)->next;
        free(tempnode);
        return temp;
    }
}

// Function to return front element without removing
int front(struct node **head_ref){
    if(*head_ref==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return (*head_ref)->data;
    }
}

// Function to return rear element without removing
int rear(struct node **head_ref){
    if(*head_ref==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        struct node *temp=*head_ref;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp->data;
    }
}

// Function to check whether queue is full or not
int isFull(struct node **head_ref){
    if(*head_ref==NULL){
        return 0;
    }
    else{
        return 1;
    }
}

// Function to check whether queue is empty or not
int isEmpty(struct node **head_ref){
    if(*head_ref==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct node *head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    printf("Front element is %d\n", front(&head));
    printf("Rear element is %d\n", rear(&head));
    dequeue(&head);
    printf("Front element after removing %d\n", front(&head));
    printf("Rear element after removing %d\n", rear(&head));
    if(isEmpty(&head)){
        printf("Queue is empty\n");
    }
    if(isFull(&head)){
        printf("Queue is full\n");
    }
    return 0;
}