//FormAI DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //for booleans

#define MAX_QUEUE_SIZE 100 //define max queue size

/*----- QUEUE IMPLEMENTATION -----*/

//structure for queue
typedef struct Queue {
    int front, rear, size;
    int* data;
} Queue;

//function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue)); //allocate memory
    queue->front = queue->size = 0;
    queue->rear = MAX_QUEUE_SIZE - 1; //initialize rear index to MAX_QUEUE_SIZE-1 because we use circular queue
    queue->data = (int*)malloc(MAX_QUEUE_SIZE * sizeof(int)); //allocate memory for data
    return queue;
}

//function to check if queue is full
bool isFull(Queue* queue) {
    return (queue->size == MAX_QUEUE_SIZE); //if the size of the queue is equal to MAX_QUEUE_SIZE, then queue is full
}

//function to check if queue is empty
bool isEmpty(Queue* queue) {
    return (queue->size == 0); //if the size of the queue is 0, then queue is empty
}

//function to add an element to the queue
void enqueue(Queue* queue, int element) {
    if(isFull(queue)) {
        printf("Error: Queue is Full\n");
        return;
    }
    else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE; //performing circular queue operation for rear index
        queue->data[queue->rear] = element; //adding element to the rear index
        queue->size++; //increasing the size of the queue
    }
}

//function to remove an element from the queue
int dequeue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Error: Queue is Empty\n");
        return -1; //returning -1 if queue is empty
    }
    else {
        int element = queue->data[queue->front]; //storing the element to be removed
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE; //performing circular queue operation for front index
        queue->size--; //decreasing the size of the queue
        return element; //returning the element that was removed
    }
}

//function to return the front element of the queue
int front(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Error: Queue is Empty\n");
        return -1;
    }
    else {
        return queue->data[queue->front];
    }
}

//function to return the rear element of the queue
int rear(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Error: Queue is Empty\n");
        return -1;
    }
    else {
        return queue->data[queue->rear];
    }
}

//function to display the elements of the queue
void display(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Error: Queue is Empty\n");
        return;
    }
    else {
        printf("Queue Elements: ");
        for(int i = 0; i < queue->size; i++) {
            printf("%d ", queue->data[(queue->front + i) % MAX_QUEUE_SIZE]); //printing elements in circular order
        }
        printf("\n");
    }
}

/*----- MAIN FUNCTION -----*/

int main() {

    Queue* queue = createQueue(); //creating a queue

    //adding elements to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    //displaying the queue
    display(queue);

    //removing elements from the queue
    printf("Removed Element: %d\n", dequeue(queue));
    printf("Removed Element: %d\n", dequeue(queue));

    //displaying the queue
    display(queue);

    //adding more elements to the queue
    enqueue(queue, 6);
    enqueue(queue, 7);

    //displaying the queue
    display(queue);

    return 0;
}