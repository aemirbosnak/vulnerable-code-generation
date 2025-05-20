//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int peek(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->front->data;
}

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void printQueue(Queue *queue) {
    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();

    printf("Enqueuing 10 elements into the queue...\n");
    for (int i = 0; i < 10; i++) {
        enqueue(queue, i);
    }

    printf("Printing the queue...\n");
    printQueue(queue);

    printf("Dequeuing 5 elements from the queue...\n");
    for (int i = 0; i < 5; i++) {
        int data = dequeue(queue);
        printf("Dequeued element: %d\n", data);
    }

    printf("Printing the queue...\n");
    printQueue(queue);

    printf("Peeking the front element of the queue...\n");
    int frontElement = peek(queue);
    printf("Front element: %d\n", frontElement);

    printf("Checking if the queue is empty...\n");
    int empty = isEmpty(queue);
    if (empty) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }

    printf("Enqueuing 5 more elements into the queue...\n");
    for (int i = 10; i < 15; i++) {
        enqueue(queue, i);
    }

    printf("Printing the queue...\n");
    printQueue(queue);

    printf("Dequeuing all remaining elements from the queue...\n");
    while (!isEmpty(queue)) {
        int data = dequeue(queue);
        printf("Dequeued element: %d\n", data);
    }

    printf("Printing the queue...\n");
    printQueue(queue);

    printf("Checking if the queue is empty...\n");
    empty = isEmpty(queue);
    if (empty) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }

    return 0;
}