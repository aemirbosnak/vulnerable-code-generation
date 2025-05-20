//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
void display(Queue* q);

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);

    int deqData = dequeue(&q);
    printf("Dequeued element: %d\n", deqData);
    display(&q);

    return 0;
}

// Initializes an empty queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Checks if the queue is empty
int isEmpty(Queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Adds an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

// Removes and returns the element from the front of the queue
int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else if (q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }

    return data;
}

// Displays the elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements:\n");
        Node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}