//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
void createQueue(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to enqueue an element
void enqueue(struct queue* q, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(struct queue* q) {
    int data = -1;
    struct node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
    }

    return data;
}

// Function to display the queue
void display(struct queue* q) {
    struct node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int dequeuedData = dequeue(&q);
    printf("Dequeued element is: %d\n", dequeuedData);

    display(&q);

    dequeuedData = dequeue(&q);
    printf("Dequeued element is: %d\n", dequeuedData);

    display(&q);

    dequeuedData = dequeue(&q);
    printf("Dequeued element is: %d\n", dequeuedData);

    display(&q);

    dequeuedData = dequeue(&q);
    printf("Dequeued element is: %d\n", dequeuedData);

    display(&q);

    return 0;
}