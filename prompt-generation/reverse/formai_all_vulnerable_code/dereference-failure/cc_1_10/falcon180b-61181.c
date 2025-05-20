//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Node structure for the Queue
typedef struct node{
    int data;
    struct node* next;
}Node;

//Queue structure
typedef struct queue{
    Node* front;
    Node* rear;
}Queue;

//Function to create an empty queue
Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//Function to check if the queue is empty
bool isEmpty(Queue* q){
    if(q->front == NULL){
        return true;
    }
    else{
        return false;
    }
}

//Function to add an element to the rear of the queue
void enqueue(Queue* q, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
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

//Function to remove an element from the front of the queue
int dequeue(Queue* q){
    int data;
    Node* temp = q->front;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        q->front = q->front->next;
        data = temp->data;
        free(temp);
        return data;
    }
}

//Function to display the elements of the queue
void display(Queue* q){
    Node* temp = q->front;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        printf("Elements of the Queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

//Main function
int main(){
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);
    return 0;
}