//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of our Queue
typedef struct {
    void *data;
    struct node *next;
} Node;

// Define the structure of our Queue
typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

// Function to create an empty Queue
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

// Function to add an element to the rear of the Queue
void enqueue(Queue *q, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (q->rear == NULL) {
        q->front = node;
    } else {
        q->rear->next = node;
    }
    q->rear = node;
    q->count++;
}

// Function to remove an element from the front of the Queue
void dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("The Queue is empty!\n");
        return;
    }
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->count--;
}

// Function to display the elements of the Queue
void display(Queue *q) {
    printf("The Queue contains:\n");
    Node *temp = q->front;
    while (temp!= NULL) {
        printf("%p ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue *q = createQueue();
    enqueue(q, "Sir Lancelot");
    enqueue(q, "King Arthur");
    enqueue(q, "Merlin");
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}