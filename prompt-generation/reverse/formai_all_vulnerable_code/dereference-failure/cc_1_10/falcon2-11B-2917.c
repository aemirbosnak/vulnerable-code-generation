//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define a queue node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a queue structure
typedef struct {
    Node* head;
    Node* tail;
    int size;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

// Function to add an element to the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->size == 0) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->size++;
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (q->size == 0) {
        return -1; // Queue is empty
    }

    int data = q->head->data;
    Node* temp = q->head;
    q->head = q->head->next;
    free(temp);

    q->size--;
    return data;
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }

    Node* curr = q->head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    displayQueue(q); // Output: 1 2 3

    printf("Dequeued: %d\n", dequeue(q)); // Output: 3

    displayQueue(q); // Output: 1 2

    return 0;
}