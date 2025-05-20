//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Queue structure
typedef struct Node *Queue;

// Function to create a new node
Queue newNode(int data) {
    Queue node = (Queue) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an element to the queue
void enqueue(Queue q, int data) {
    Queue node = newNode(data);
    node->next = q;
    q = node;
}

// Function to remove an element from the queue
int dequeue(Queue q) {
    if (q == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Queue temp = q;
    int data = temp->data;
    q = q->next;
    free(temp);
    return data;
}

// Function to display the queue
void display(Queue q) {
    if (q == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Queue temp = q;
    printf("Queue elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to test the queue
void testQueue() {
    Queue q = NULL;
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
}

int main() {
    testQueue();
    return 0;
}