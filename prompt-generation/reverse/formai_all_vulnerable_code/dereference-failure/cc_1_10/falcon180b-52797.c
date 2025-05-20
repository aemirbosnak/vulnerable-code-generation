//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//node structure definition
struct node{
    int data;
    struct node* next;
};

//queue structure definition
struct queue{
    struct node* front;
    struct node* rear;
};

//function to create an empty queue
struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

//function to check if the queue is empty
int isEmpty(struct queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

//function to add an element to the rear of the queue
void enqueue(struct queue* q, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if(isEmpty(q))
        q->front = temp;
    else
        q->rear->next = temp;

    q->rear = temp;
}

//function to remove an element from the front of the queue
int dequeue(struct queue* q){
    int data;
    struct node* temp = q->front;

    if(isEmpty(q))
        printf("Queue is empty\n");
    else{
        data = temp->data;
        q->front = temp->next;

        if(q->front == NULL)
            q->rear = NULL;

        free(temp);
    }

    return data;
}

//function to display the elements of the queue
void display(struct queue* q){
    struct node* temp = q->front;

    if(isEmpty(q))
        printf("Queue is empty\n");
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

    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    enqueue(q, 50);
    enqueue(q, 60);

    display(q);

    return 0;
}