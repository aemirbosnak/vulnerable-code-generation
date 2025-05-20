//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: artistic
/*
               _                      _   _            
              | |                    | | | |           
              | |__   __ _ _ __   __ _| | | | ___ _   _ 
              | '_ \ / _` | '_ \ / _` | | | |/ _ \ | | |
              | | | | (_| | | | | (_| | |_| |  __/ |_| |
              |_| |_|\__,_|_| |_|\__, |\__, |\___|\__, |
                                |___/ |___/       |___/
              _____    _   _      _   _                 _ 
             / ____|  | | | |    | | | |               | |
            | (___   | |_| | ___| |_| | ___   ___  __| |
             \___ \  |  _  |/ _ \  _  |/ _ \ / _ \/ _` |
             ____) | | | | |  __/ | | | (_) |  __/ (_| |
            |_____/  |_| |_|\___|_| |_|\___/ \___|\__,_|
            

*/
#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the queue
struct Node {
    int data;
    struct Node *next;
};

// Structure of the queue
struct Queue {
    struct Node *front;
    struct Node *rear;
    int size;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }

    struct Node *temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return data;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->size == 0;
}

// Function to print the queue
void printQueue(struct Queue *queue) {
    struct Node *temp = queue->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Driver code to test the queue
int main() {
    struct Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    printQueue(queue);

    return 0;
}