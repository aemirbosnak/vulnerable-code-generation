//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    node* temp = front;
    front = front->next;
    free(temp);
    if(front == NULL){
        rear = NULL;
    }
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    node* temp = front;
    printf("Elements in the queue are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(50);
    enqueue(60);
    enqueue(70);
    display();
    return 0;
}