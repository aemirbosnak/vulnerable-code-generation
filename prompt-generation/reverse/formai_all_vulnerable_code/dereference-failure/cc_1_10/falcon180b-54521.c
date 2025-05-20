//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node{
    int data;
    struct node *next;
}node;

node *front = NULL;
node *rear = NULL;

void enqueue(int value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    node *temp = front;
    if(front == NULL){
        printf("\nQueue Underflow");
        return;
    }
    else{
        front = front->next;
    }
    free(temp);
}

void display(){
    node *temp = front;
    if(front == NULL){
        printf("\nQueue is empty");
        return;
    }
    else{
        printf("\nQueue elements are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);

    printf("\nInitial Queue: ");
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    printf("\n\nAfter deleting 10 elements: ");
    display();

    enqueue(110);
    enqueue(120);
    enqueue(130);
    enqueue(140);
    enqueue(150);
    enqueue(160);
    enqueue(170);
    enqueue(180);
    enqueue(190);
    enqueue(200);

    printf("\n\nQueue after adding 10 more elements: ");
    display();

    return 0;
}