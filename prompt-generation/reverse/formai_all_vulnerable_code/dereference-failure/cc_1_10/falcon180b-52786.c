//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

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
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//Function to check if the queue is empty
int isEmpty(struct Queue* q){
    if(q->front == NULL && q->rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to enqueue an element
void enqueue(struct Queue* q, int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if(isEmpty(q)){
        q->front = n;
        q->rear = n;
    }
    else{
        q->rear->next = n;
        q->rear = n;
    }
}

//Function to dequeue an element
int dequeue(struct Queue* q){
    int data = -1;
    struct node* n = q->front;
    if(!isEmpty(q)){
        data = n->data;
        q->front = n->next;
        free(n);
        if(q->front == NULL){
            q->rear = NULL;
        }
    }
    return data;
}

//Function to display the queue
void display(struct Queue* q){
    struct node* n = q->front;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue: ");
        while(n!= NULL){
            printf("%d ", n->data);
            n = n->next;
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
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    return 0;
}