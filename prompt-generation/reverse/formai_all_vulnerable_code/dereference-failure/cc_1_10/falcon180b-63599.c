//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// define the structure of a node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// define the structure of the queue
typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

// create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

// check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->count++;
}

// remove an element from the front of the queue
int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(0);
    }
    data = q->front->data;
    q->front = q->front->next;
    q->count--;
    free(temp);
    return data;
}

// display the elements in the queue
void display(Queue* q) {
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Elements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    return 0;
}