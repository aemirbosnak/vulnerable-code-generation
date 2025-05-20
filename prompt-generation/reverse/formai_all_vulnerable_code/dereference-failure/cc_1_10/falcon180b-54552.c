//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

//Node structure for queue
struct Node{
    int data;
    struct Node* next;
};

//Queue structure
struct Queue{
    struct Node* front;
    struct Node* rear;
};

//Function to create an empty queue
void createQueue(struct Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

//Function to check if queue is empty
int isEmpty(struct Queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

//Function to check if queue is full
int isFull(struct Queue* q){
    if(q->rear == NULL)
        return 0;
    else
        return 1;
}

//Function to enqueue an element
void enqueue(struct Queue* q, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q))
        q->front = q->rear = newNode;
    else
        q->rear->next = newNode;
    q->rear = newNode;
}

//Function to dequeue an element
int dequeue(struct Queue* q){
    int data;
    struct Node* temp = q->front;
    if(isEmpty(q))
        printf("\nQueue Underflow");
    else{
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

//Function to display the queue
void display(struct Queue* q){
    struct Node* temp = q->front;
    printf("\nQueue: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//Main function
int main(){
    struct Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    printf("\nDequeued element: %d", dequeue(&q));
    display(&q);
    printf("\nDequeued element: %d", dequeue(&q));
    display(&q);
    printf("\nDequeued element: %d", dequeue(&q));
    display(&q);
    return 0;
}