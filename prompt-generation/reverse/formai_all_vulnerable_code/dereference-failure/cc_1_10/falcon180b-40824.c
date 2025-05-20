//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(rear == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d is enqueued\n",data);
}

int dequeue(){
    int data;
    node* temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
        exit(0);
    }
    data = front->data;
    front = front->next;
    free(temp);
    printf("%d is dequeued\n",data);
    return data;
}

void display(){
    node* temp = front;
    printf("Elements in the queue are: ");
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, data;
    do{
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                printf("Dequeued data is: %d\n",data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 4);
    return 0;
}