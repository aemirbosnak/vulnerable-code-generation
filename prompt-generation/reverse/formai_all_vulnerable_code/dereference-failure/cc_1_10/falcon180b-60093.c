//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

//Node structure
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

//Function to create an empty queue
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

//Function to check if the queue is empty
int isEmpty(struct Queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

//Function to check if the queue is full
int isFull(struct Queue* q){
    if(q->count == MAX_SIZE)
        return 1;
    else
        return 0;
}

//Function to add an element to the rear of the queue
void enqueue(struct Queue* q, int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if(isEmpty(q))
        q->front = q->rear = node;
    else
        q->rear->next = node;

    q->rear = node;
    q->count++;
}

//Function to remove an element from the front of the queue
void dequeue(struct Queue* q){
    struct Node* node = q->front;

    if(isEmpty(q))
        printf("Queue is empty\n");
    else if(q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;

    free(node);
    q->count--;
}

//Function to display the elements of the queue
void display(struct Queue* q){
    struct Node* temp = q->front;

    if(isEmpty(q))
        printf("Queue is empty\n");
    else{
        printf("Elements of the Queue are:\n");
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
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    return 0;
}