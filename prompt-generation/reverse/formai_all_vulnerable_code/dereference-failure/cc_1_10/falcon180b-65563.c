//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

//Node structure for creating a linked list
struct Node{
    int data;
    struct Node* next;
};

//Queue structure for implementing queue
struct Queue{
    struct Node* front;
    struct Node* rear;
};

//Function for creating a new node with given data
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function for creating an empty queue
struct Queue* createQueue(){
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

//Function for checking if the queue is empty
int isEmpty(struct Queue* queue){
    if(queue->front == NULL && queue->rear == NULL)
        return 1;
    else
        return 0;
}

//Function for adding an element to the rear of the queue
void enqueue(struct Queue* queue, int data){
    struct Node* newNode = createNode(data);

    if(isEmpty(queue))
        queue->front = newNode;
    else
        queue->rear->next = newNode;

    queue->rear = newNode;
}

//Function for removing an element from the front of the queue
int dequeue(struct Queue* queue){
    int data;
    struct Node* tempNode;

    if(isEmpty(queue))
        printf("Queue is empty\n");
    else{
        tempNode = queue->front;
        data = tempNode->data;
        queue->front = tempNode->next;
        free(tempNode);
    }

    return data;
}

//Function for displaying the elements in the queue
void display(struct Queue* queue){
    struct Node* tempNode = queue->front;

    if(isEmpty(queue))
        printf("Queue is empty\n");
    else{
        printf("Queue elements are: ");
        while(tempNode!= NULL){
            printf("%d ", tempNode->data);
            tempNode = tempNode->next;
        }
        printf("\n");
    }
}

//Driver code for testing the queue implementation
int main(){
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    int dequeuedData = dequeue(queue);
    printf("Dequeued data is: %d\n", dequeuedData);

    display(queue);

    return 0;
}