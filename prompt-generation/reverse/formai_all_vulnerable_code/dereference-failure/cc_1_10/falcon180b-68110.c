//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if(front == NULL && rear == NULL){
        front = new_node;
        rear = new_node;
    }
    else if(rear == NULL){
        rear = new_node;
        rear->next = front;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(){
    if(front == NULL){
        printf("\nQueue is empty");
        return;
    }
    printf("\nDeleted element is %d", front->data);
    struct node* temp = front;
    front = front->next;
    free(temp);

    if(front == NULL){
        rear = NULL;
    }
}

void display(){
    if(front == NULL){
        printf("\nQueue is empty");
        return;
    }
    struct node* temp = front;
    printf("\nElements in the queue are: ");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp!= front);
}

int main(){
    int choice, value;

    do{
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while(choice!= 4);

    return 0;
}