//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5 // Maximum size of queue

// Queue implementation
typedef struct queue{
    int data[MAX_QUEUE_SIZE]; // Data container
    int front, rear; // Index for the front and rear
    int counter; //Counter variable to keep track of number of elements in queue
}Queue;

// Initializes the queue
Queue* createQueue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q -> front = 0;
    q -> rear = -1;
    q -> counter = 0;
    return q;
}

// Checks whether the queue is empty or not
int isEmpty(Queue* q){
    if(q -> counter == 0) //If no elements in queue
        return 1;
    else
        return 0;
}

// Checks whether the queue is full or not
int isFull(Queue* q){
    if(q -> counter == MAX_QUEUE_SIZE) //If max limit reached for queue
        return 1;
    else
        return 0;
}

// Adds an element to the queue
void enqueue(Queue* q, int element){
    if(isFull(q)) //Check if queue is full
        printf("Sorry, Queue is full!\n");
    else{
        q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE; //Circular updating rear index
        q -> data[q -> rear] = element; //Storing element at the rear index
        q -> counter++;
        printf("Successfully Enqueued! \n");
    }
}

// Removes an element from the queue
void dequeue(Queue* q){
    if(isEmpty(q)) //Check if queue is empty
        printf("Sorry, Queue is empty!\n");
    else{
        printf("Dequeued : %d\n", q -> data[q -> front]); //Priting and removing initial element
        q -> front = (q -> front + 1) % MAX_QUEUE_SIZE; //Circular updating front index
        q -> counter--;
    }
}

// Displays the queue from front to rear
void display(Queue* q){
    if(isEmpty(q)) //Check if queue is empty
        printf("Sorry, Queue is empty!\n");
    else{
        printf("Queue contents: ["); 
        int i, j; //Defining two counters to display queue contents
        for(i = q -> front, j = 0; j < q -> counter; j++){ //Looping through all elements in queue
            printf("%d", q -> data[i]); //print each element
            i = (i + 1) % MAX_QUEUE_SIZE; //update sequential index, to display elements in correct order
            if(j != q -> counter - 1) //Checking if printing of comma is necessary
                printf(", "); 
        }
        printf("]\n");
    }
}

// Driver function to test the queue implementation
int main(){
    Queue* q = createQueue();
    printf("Queue Initialization Successful!\n\n");
    printf("Adding 5 elements to the queue...\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    printf("\nQueue after additions:\n");
    display(q);
    printf("\nRemoving 3 elements from the queue...\n");
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printf("\nQueue after removals:\n");
    display(q);
    printf("\nAdding 2 elements to the queue...\n");
    enqueue(q, 60);
    enqueue(q, 70);
    printf("\nQueue after additions:\n");
    display(q);
    printf("\nRemoving remaining elements from the queue...\n");
    dequeue(q);
    dequeue(q);
    printf("\nQueue after removals:\n");
    display(q);
    return 0;
}