//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100 

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* front = NULL; 
Node* rear = NULL;

int isQueueEmpty(){
    if(front == NULL && rear == NULL){
        return 1;
    }
    return 0;
}

int isQueueFull(){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        free(newNode);
        return 1;
    }
    free(newNode);
    return 0;
}

void enqueue(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(isQueueFull()){
        printf("Queue is full.\n");
        free(newNode);
        return;
    }
    if(isQueueEmpty()){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue(){
    if(isQueueEmpty()){
        printf("Queue is empty.\n");
        return -1;
    }
    Node* popNode = front;
    int data = front->data;
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    free(popNode);
    return data;
}

void display(){
    if(isQueueEmpty()){
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    printf("*****************************\n");
    printf("** C Queue Implementation **\n");
    printf("*****************************\n\n");

    int choice, value;
    while(1){
        printf("Enter your choice\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value != -1){
                    printf("%d dequeued successfully!\n",value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you for using the program! Goodbye :)\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}