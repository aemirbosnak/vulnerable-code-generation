//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// node structure definition
struct node {
    int data;
    struct node* next;
};

// queue structure definition
typedef struct {
    struct node* front;
    struct node* rear;
} Queue;

// function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL)
        return 1;
    else
        return 0;
}

// function to add an element to the rear of the queue
void enqueue(Queue* queue, int value) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;

    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int value = -1;
    struct node* node = queue->front;

    if (!isEmpty(queue)) {
        value = node->data;
        queue->front = node->next;

        if (queue->front == NULL)
            queue->rear = NULL;

        free(node);
    }

    return value;
}

// function to display the elements in the queue
void display(Queue* queue) {
    struct node* node = queue->front;

    if (isEmpty(queue))
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        while (node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// main function
int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    int value = dequeue(queue);
    printf("Dequeued value: %d\n", value);

    display(queue);

    return 0;
}