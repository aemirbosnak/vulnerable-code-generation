//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// A Queue Node.
struct QNode {
    int data;
    struct QNode* next;
};

// A Queue.
struct Queue {
    struct QNode *front, *rear;
};

// Create a new Queue.
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Enqueue an element into the Queue.
void enQueue(struct Queue* queue, int data) {
    struct QNode* newNode = (struct QNode*) malloc(sizeof(struct QNode));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the Queue.
int deQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    struct QNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

// Check if the Queue is empty.
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Print the Queue.
void printQueue(struct Queue* queue) {
    struct QNode* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function.
int main() {
    // Create a new Queue.
    struct Queue* queue = createQueue();

    // Enqueue some elements into the Queue.
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    // Print the Queue.
    printQueue(queue);

    // Dequeue some elements from the Queue.
    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));

    // Print the Queue again.
    printQueue(queue);

    // Check if the Queue is empty.
    if (isEmpty(queue)) {
        printf("The Queue is empty.\n");
    } else {
        printf("The Queue is not empty.\n");
    }

    return 0;
}