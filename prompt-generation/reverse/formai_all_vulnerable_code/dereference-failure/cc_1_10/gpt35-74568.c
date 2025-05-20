//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h> 
#include <stdlib.h> 

//Struct for the Queue
typedef struct Queue{
    int front, rear, size;
    unsigned int capacity;
    int* array;
} Queue;

//Function to create a new queue with the capacity given by the user
Queue* createQueue(unsigned int capacity){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

//Function to check if the queue is full
int isFull(Queue* queue){
    return (queue->size == queue->capacity);
}

//Function to check if the queue is empty
int isEmpty(Queue* queue){
    return (queue->size == 0);
}

//Function to add an element to the queue
void enqueue(Queue* queue, int item){
    if(isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

//Function to remove an element from the queue
int dequeue(Queue* queue){
    if(isEmpty(queue)) return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

//Function to get the element at the front of the queue without removing it
int front(Queue* queue){
    if(isEmpty(queue)) return -1;
    return queue->array[queue->front];
}

//Function to get the element at the rear of the queue without removing it
int rear(Queue* queue){
    if(isEmpty(queue)) return -1;
    return queue->array[queue->rear];
}

//Driver function to test the queue operations
int main(){
    
    printf("This program demonstrates the implementation of a Queue using C programming language using a circle like mathematical pattern!\n");
    
    //Creating a queue with capacity of 5 elements
    printf("Creating a queue with capacity of 5 elements!\n");
    Queue* queue = createQueue(5);
    printf("\n");
    
    //Adding elements to the queue
    printf("Adding elements to the queue!\n");
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("\n");
    
    //Removing elements from the queue
    printf("Removing elements from the queue!\n");
    printf("Element removed from the front of the queue: %d\n", dequeue(queue));
    printf("Element removed from the front of the queue: %d\n", dequeue(queue));
    printf("\n");
    
    //Adding more elements to the queue
    printf("Adding more elements to the queue!\n");
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    printf("\n");
    
    //Checking the front and rear elements of the queue
    printf("Checking the front and rear elements of the queue!\n");
    printf("Front element of the queue: %d\n", front(queue));
    printf("Rear element of the queue: %d\n", rear(queue));
    printf("\n");

    //Removing all the elements from the queue
    printf("Removing all the elements from the queue!\n");
    while(!isEmpty(queue)){
        printf("Element removed from the front of the queue: %d\n", dequeue(queue));
    }

    return 0;
}