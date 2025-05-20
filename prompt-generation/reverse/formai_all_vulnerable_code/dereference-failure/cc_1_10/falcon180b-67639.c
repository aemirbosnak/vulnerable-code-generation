//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

//Node structure for Queue
struct Node{
    int data;
    struct Node* next;
};

//Queue structure
struct Queue{
    struct Node* front;
    struct Node* rear;
    int count;
};

//Function to create an empty Queue
void createQueue(struct Queue* q){
    q->front = q->rear = NULL;
    q->count = 0;
}

//Function to check if the Queue is empty
int isEmpty(struct Queue* q){
    if(q->front == NULL)
        return 1;
    else
        return 0;
}

//Function to check if the Queue is full
int isFull(struct Queue* q){
    if(q->rear == NULL)
        return 0;
    else
        return 1;
}

//Function to add an element to the Queue
void enqueue(struct Queue* q, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Queue Overflow\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if(isEmpty(q)){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
    q->count++;
}

//Function to remove an element from the Queue
int dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        exit(0);
    }
    int data = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
    q->count--;
    return data;
}

//Function to display the elements of the Queue
void display(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    struct Node* temp = q->front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    int data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);
    display(&q);
    data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);
    display(&q);
    data = dequeue(&q);
    printf("Dequeued element is: %d\n", data);
    display(&q);
    return 0;
}