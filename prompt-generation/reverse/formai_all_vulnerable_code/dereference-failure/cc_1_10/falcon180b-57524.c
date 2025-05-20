//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// node structure
typedef struct node{
    int data;
    struct node* next;
}Node;

// queue structure
typedef struct queue{
    Node* front;
    Node* rear;
}Queue;

// function to create an empty queue
Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL){
        printf("Memory error\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    return q;
}

// function to check if the queue is empty
bool isEmpty(Queue* q){
    return q->front == NULL;
}

// function to check if the queue is full
bool isFull(Queue* q){
    return q->rear == NULL;
}

// function to add an element to the rear of the queue
void enqueue(Queue* q, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// function to remove an element from the front of the queue
void dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue underflow\n");
        exit(0);
    }
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if(isEmpty(q)){
        q->rear = NULL;
    }
}

// function to display the elements of the queue
void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements of the queue are:\n");
        Node* temp = q->front;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}