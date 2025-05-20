//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    if(rear == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    printf("%d is enqueued to the queue\n",x);
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("%d is dequeued from the queue\n",front->data);
        node* temp = front;
        front = front->next;
        free(temp);
        if(front == NULL){
            rear = NULL;
        }
    }
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are: ");
        node* temp = front;
        while(temp!= NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}