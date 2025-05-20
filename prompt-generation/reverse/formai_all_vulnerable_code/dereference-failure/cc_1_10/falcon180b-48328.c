//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(rear == NULL){
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;

    printf("Queue elements are: ");

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

    display();

    dequeue();

    display();

    dequeue();

    display();

    dequeue();

    return 0;
}