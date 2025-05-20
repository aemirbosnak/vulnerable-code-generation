//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* structure of a node */
struct Node {
    int data;
    struct Node *next;
};

/* structure of a queue */
struct Queue {
    struct Node *front;
    struct Node *rear;
};

/* function to create an empty queue */
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/* function to add an element to the rear of the queue */
void enqueue(struct Queue *queue, int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

/* function to remove an element from the front of the queue */
int dequeue(struct Queue *queue) {
    int data = -1;
    struct Node *node = queue->front;

    if (queue->front!= NULL) {
        data = queue->front->data;
        queue->front = queue->front->next;

        if (queue->front == NULL)
            queue->rear = NULL;
    }

    free(node);
    return data;
}

/* function to display the elements of the queue */
void display(struct Queue *queue) {
    struct Node *node = queue->front;

    if (queue->front == NULL)
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        while (node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

/* main function */
int main() {
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);

    dequeue(queue);
    display(queue);

    dequeue(queue);
    display(queue);

    dequeue(queue);
    display(queue);

    dequeue(queue);
    display(queue);

    return 0;
}