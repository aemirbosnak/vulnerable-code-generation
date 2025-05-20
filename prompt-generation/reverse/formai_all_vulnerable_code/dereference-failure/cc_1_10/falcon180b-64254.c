//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

//Node structure definition
struct node{
    int data;
    struct node* next;
};

//Queue structure definition
struct queue{
    struct node* front;
    struct node* rear;
};

//Function to create an empty queue
struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

//Function to check if the queue is empty
bool isEmpty(struct queue* q){
    return (q->front == NULL && q->rear == NULL);
}

//Function to add an element to the rear of the queue
void enqueue(struct queue* q, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if(isEmpty(q)){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

//Function to remove an element from the front of the queue
int dequeue(struct queue* q){
    int value = -1;
    struct node* temp = q->front;

    if(!isEmpty(q)){
        value = q->front->data;
        q->front = q->front->next;

        if(q->front == NULL){
            q->rear = NULL;
        }
    }

    free(temp);
    return value;
}

//Function to display the elements in the queue
void display(struct queue* q){
    struct node* temp = q->front;

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements in the queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    int value = dequeue(q);
    printf("Dequeued value is: %d\n", value);

    display(q);

    value = dequeue(q);
    printf("Dequeued value is: %d\n", value);

    display(q);

    value = dequeue(q);
    printf("Dequeued value is: %d\n", value);

    display(q);

    value = dequeue(q);
    printf("Dequeued value is: %d\n", value);

    display(q);

    return 0;
}