//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//Node structure for creating a linked list
struct Node{
    int data;
    struct Node* next;
};

//Queue structure using linked list
struct Queue{
    struct Node* front;
    struct Node* rear;
};

//Function to initialize the queue
void initQueue(struct Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

//Function to check if the queue is empty
int isEmpty(struct Queue* q){
    return q->front == NULL;
}

//Function to check if the queue is full
int isFull(struct Queue* q){
    return q->rear == NULL;
}

//Function to enqueue an element
void enqueue(struct Queue* q, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//Function to dequeue an element
int dequeue(struct Queue* q){
    int data = -1;

    if(!isEmpty(q)){
        struct Node* temp = q->front;
        data = temp->data;
        q->front = temp->next;

        if(q->front == NULL){
            q->rear = NULL;
        }

        free(temp);
    }

    return data;
}

//Function to display the queue
void display(struct Queue* q){
    struct Node* temp = q->front;

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements in the queue are: ");

        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int dequeuedData = dequeue(&q);
    printf("Dequeued element is: %d\n", dequeuedData);

    display(&q);

    return 0;
}