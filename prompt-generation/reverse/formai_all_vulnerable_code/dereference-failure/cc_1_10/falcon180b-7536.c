//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Node structure definition */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* Queue structure definition */
typedef struct {
    Node* front;
    Node* rear;
} Queue;

/* Function to create an empty queue */
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) {
        printf("Error: Memory not allocated\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

/* Function to check if the queue is empty */
int isEmpty(Queue* q) {
    if(q->front == NULL && q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/* Function to check if the queue is full */
int isFull(Queue* q) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL) {
        printf("Error: Memory not allocated\n");
        exit(0);
    }
    free(temp);
    return 0;
}

/* Function to add an element to the rear of the queue */
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error: Memory not allocated\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    if(isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

/* Function to remove an element from the front of the queue */
int dequeue(Queue* q) {
    int value;
    Node* temp = q->front;
    if(isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(0);
    } else if(q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        value = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    return value;
}

/* Function to display the elements in the queue */
void display(Queue* q) {
    Node* temp = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue are: ");
        while(temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    /* Creating an empty queue */
    Queue* q = createQueue();

    /* Adding elements to the queue */
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    /* Displaying the elements in the queue */
    display(q);

    /* Removing elements from the queue */
    printf("Removed element is: %d\n", dequeue(q));
    printf("Removed element is: %d\n", dequeue(q));

    /* Displaying the elements in the queue */
    display(q);

    /* Freeing the memory allocated for the queue */
    free(q);

    return 0;
}