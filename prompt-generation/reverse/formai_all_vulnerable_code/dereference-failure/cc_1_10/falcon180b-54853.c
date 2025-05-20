//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(int value){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    if(rear == NULL){
        front = new_node;
        rear = new_node;
    }else{
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(){
    node* temp = front;
    if(front == NULL && rear == NULL){
        printf("\nQueue is empty!");
        return;
    }else if(front == NULL){
        rear = NULL;
        front = rear;
    }else{
        front = front->next;
    }
    printf("\nDeleted element is %d", temp->data);
    free(temp);
}

void display(){
    node* temp = front;
    if(front == NULL && rear == NULL){
        printf("\nQueue is empty!");
        return;
    }
    printf("\nQueue elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int is_empty(){
    if(front == NULL && rear == NULL){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int choice, value;
    while(1){
        printf("\n\nEnter 1 to enqueue an element\nEnter 2 to dequeue an element\nEnter 3 to display the queue\nEnter 4 to check if the queue is empty\nEnter 5 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("\nEnter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                if(is_empty()){
                    printf("\nQueue is empty!");
                }else{
                    printf("\nQueue is not empty!");
                }
                break;
            }
            case 5:{
                exit(0);
            }
            default:{
                printf("\nInvalid choice!");
            }
        }
    }
    return 0;
}