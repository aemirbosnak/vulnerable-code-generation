//FormAI DATASET v1.0 Category: Queue Implementation ; Style: immersive
//Welcome to the world of Queues!
//I am here to help you with a unique implementation of a Queue in C!

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

//A Node struct to represent an element in the queue
struct Node {
    int data;
    struct Node *next;
};

//A Queue struct to represent the queue
struct Queue {
    struct Node *front;
    struct Node *rear;
    int size;
    int capacity;
};

//A function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//A function to create a new queue
struct Queue *createQueue(int capacity) {
    struct Queue *newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    newQueue->capacity = capacity;

    return newQueue;
}

//A function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->size == 0;
}

//A function to check if the queue is full
int isFull(struct Queue *queue) {
    return queue->size == queue->capacity;
}

//A function to enqueue an element
void enqueue(struct Queue *queue, int data) {
    if(isFull(queue)) {
        printf("Sorry, the queue is full.\n");
        return;
    }

    struct Node *newNode = createNode(data);

    if(queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
    printf("%d has been added to the queue.\n", data);
}

//A function to dequeue an element
void dequeue(struct Queue *queue) {
    if(isEmpty(queue)) {
        printf("Sorry, the queue is empty.\n");
        return;
    }

    struct Node *temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;
    free(temp);

    if(queue->front == NULL) {
        queue->rear = NULL;
    }

    queue->size--;
    printf("%d has been removed from the queue.\n", data);
}

//A function to display the elements in the queue
void display(struct Queue *queue) {
    if(isEmpty(queue)) {
        printf("Sorry, the queue is empty.\n");
        return;
    }

    struct Node *temp = queue->front;
    printf("The elements in the queue are: ");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

//Main function to test the Queue implementation
int main() {
    printf("Welcome to the Queue program!\n");
    printf("Let's create a new Queue with a capacity of %d.\n", MAX_SIZE);
    struct Queue *queue = createQueue(MAX_SIZE);

    printf("Adding the first element to the queue.\n");
    enqueue(queue, 10);

    printf("The current size of the queue is %d.\n", queue->size);

    printf("Adding more elements to the queue.\n");
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("The current size of the queue is %d.\n", queue->size);

    printf("Displaying the elements in the queue.\n");
    display(queue);

    printf("Removing an element from the queue.\n");
    dequeue(queue);

    printf("The current size of the queue is %d.\n", queue->size);

    printf("Displaying the elements in the queue.\n");
    display(queue);

    printf("Adding more elements to the queue.\n");
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    enqueue(queue, 100);

    printf("The current size of the queue is %d.\n", queue->size);

    printf("Displaying the elements in the queue.\n");
    display(queue);

    printf("Trying to enqueue another element when the queue is full.\n");
    enqueue(queue, 110);

    printf("Removing all elements from the queue.\n");
    while(!isEmpty(queue)) {
        dequeue(queue);
    }

    printf("The current size of the queue is %d.\n", queue->size);

    printf("Trying to dequeue an element when the queue is empty.\n");
    dequeue(queue);

    printf("Thanks for using the Queue program!\n");

    return 0;
}