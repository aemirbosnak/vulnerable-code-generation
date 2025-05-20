//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Queue node structure
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Function to initialize the queue
void initQueue(struct QueueNode** queue) {
    *queue = NULL;
}

// Function to insert an element in the queue
void enqueue(struct QueueNode** queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = *queue;
    *queue = newNode;
}

// Function to delete an element from the queue
struct QueueNode* dequeue(struct QueueNode** queue) {
    struct QueueNode* temp = *queue;
    struct QueueNode* temp2 = temp->next;
    free(temp);
    *queue = temp2;
    return temp2;
}

// Function to print the queue
void printQueue(struct QueueNode* queue) {
    struct QueueNode* temp = queue;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the queue
void reverseQueue(struct QueueNode** queue) {
    struct QueueNode* temp1 = *queue;
    struct QueueNode* temp2 = NULL;
    while (temp1!= NULL) {
        struct QueueNode* temp3 = temp1->next;
        temp1->next = temp2;
        temp2 = temp1;
        temp1 = temp3;
    }
    *queue = temp2;
}

int main() {
    struct QueueNode* queue = NULL;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printQueue(queue);

    reverseQueue(&queue);

    printQueue(queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    printQueue(queue);

    return 0;
}