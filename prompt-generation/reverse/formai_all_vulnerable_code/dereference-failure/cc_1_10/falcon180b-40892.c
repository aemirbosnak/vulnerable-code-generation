//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Node structure definition
struct node{
    int data;
    struct node* next;
};

//Queue structure definition
struct Queue{
    struct node* front;
    struct node* rear;
};

//Function to create an empty queue
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

//Function to check if the queue is empty
int isEmpty(struct Queue* q){
    if(q->front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to add an element to the rear of the queue
void enqueue(struct Queue* q, int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//Function to remove an element from the front of the queue
int dequeue(struct Queue* q){
    int value;
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        struct node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        free(temp);
        return value;
    }
}

//Function to display the elements in the queue
void display(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        struct node* temp = q->front;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Deleted element: %d\n", dequeue(q));
    display(q);
    return 0;
}