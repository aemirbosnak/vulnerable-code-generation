//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// **Node Definition**
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// **Queue Implementation**
typedef struct Queue {
    Node *front, *rear;
} Queue;

// **Function Declarations**
Queue *createQueue();              // creates a new queue
void enqueue(Queue *, int);       // inserts an element at the rear of the queue
int dequeue(Queue *);            // deletes an element from the front of the queue
int peek(Queue *);               // returns the front element of the queue
int isEmpty(Queue *);            // checks if the queue is empty
void display(Queue *);            // displays the elements of the queue
int count(Queue *);              // returns the number of elements in the queue
void destroyQueue(Queue *);       // deallocates the memory for the queue

// **Function Definitions**
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;  // queue is empty
    }

    Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    int data = temp->data;
    free(temp);
    return data;
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;  // queue is empty
    }

    return queue->front->data;
}

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int count(Queue *queue) {
    int count = 0;
    Node *temp = queue->front;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void destroyQueue(Queue *queue) {
    Node *temp;

    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }

    free(queue);
}

// **Driver Code**
int main() {
    Queue *queue = createQueue();

    printf("Enqueuing elements: 1, 2, 3, 4, 5\n");
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Displaying the queue: ");
    display(queue);

    printf("Dequeuing an element: %d\n", dequeue(queue));

    printf("Displaying the queue: ");
    display(queue);

    printf("Peeking at the front element: %d\n", peek(queue));

    printf("Checking if the queue is empty: %s\n", isEmpty(queue) ? "Yes" : "No");

    printf("Counting the number of elements in the queue: %d\n", count(queue));

    printf("Destroying the queue\n");
    destroyQueue(queue);

    return 0;
}