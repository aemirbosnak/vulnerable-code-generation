//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Structure for the queue elements
struct QueueElement {
    struct QueueElement *prev;
    struct QueueElement *next;
    int data;
};

// Structure for the queue
struct Queue {
    struct QueueElement *head;
    struct QueueElement *tail;
};

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->head == NULL;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueElement* newNode = (struct QueueElement*)malloc(sizeof(struct QueueElement));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        newNode->prev = queue->tail;
        queue->tail = newNode;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }

    struct QueueElement* temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    return temp->data;
}

// Function to display the elements of the queue
void displayQueue(struct Queue* queue) {
    struct QueueElement* current = queue->head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    displayQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));

    displayQueue(queue);

    return 0;
}