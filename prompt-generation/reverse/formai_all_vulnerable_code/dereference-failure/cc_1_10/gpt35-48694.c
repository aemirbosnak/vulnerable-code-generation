//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    printf("Queue created. Your perception of time is now distorted.\n");
    return q;
}

void enqueue(Queue *q, int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(q->front == NULL && q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = q->rear->next;
    }
    q->size++;
    printf("Element %d warped into the queue. Your reality is becoming unstable.\n", data);
}

int dequeue(Queue *q) {
    if(q->front == NULL) {
        printf("The queue is empty. Your mind is now lost in an infinite loop.\n");
        exit(1);
    }

    int data = q->front->data;
    Node *temp = q->front;

    if(q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    q->size--;
    printf("Element %d has been ejected from the queue. You feel your sense of reality slipping away.\n", data);
    return data;
}

void displayQueue(Queue *q) {
    if(q->front == NULL) {
        printf("The queue is empty. You are lost in the void.\n");
        return;
    }

    printf("Your perception of the queue: [ ");
    Node *temp = q->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
    printf("You hear a strange humming noise around you. This may not be reality after all.\n");
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 1);
    displayQueue(q);
    enqueue(q, 2);
    displayQueue(q);
    enqueue(q, 3);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
    dequeue(q);
    return 0;
}