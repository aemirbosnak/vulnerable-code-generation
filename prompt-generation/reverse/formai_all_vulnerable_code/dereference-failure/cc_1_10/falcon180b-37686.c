//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//node structure
struct node{
    int data;
    struct node* next;
};

//queue structure
struct queue{
    struct node* front;
    struct node* rear;
};

//initializing an empty queue
void initQueue(struct queue* q){
    q->front = NULL;
    q->rear = NULL;
}

//checking if the queue is empty
bool isEmptyQueue(struct queue* q){
    if(q->front == NULL && q->rear == NULL){
        return true;
    }
    else{
        return false;
    }
}

//adding an element to the rear of the queue
void enqueue(struct queue* q, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmptyQueue(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//removing an element from the front of the queue
int dequeue(struct queue* q){
    int data;
    struct node* temp = q->front;

    if(isEmptyQueue(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        data = temp->data;
        q->front = temp->next;
        free(temp);
        return data;
    }
}

//displaying the elements of the queue
void displayQueue(struct queue* q){
    struct node* temp = q->front;

    if(isEmptyQueue(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements of the queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct queue q;

    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q);

    int data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);

    displayQueue(&q);

    return 0;
}