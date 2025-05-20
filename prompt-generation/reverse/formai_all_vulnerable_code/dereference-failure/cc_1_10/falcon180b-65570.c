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

void enqueue(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(front == NULL && rear == NULL){
        front = new_node;
        rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        exit(0);
    }
    struct node* temp = front;
    printf("%d is dequeued from the queue\n",temp->data);
    front = front->next;
    free(temp);
}

void display(){
    printf("Queue elements are: ");
    struct node* temp = front;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    dequeue();
    enqueue(4);
    enqueue(5);
    display();
    return 0;
}