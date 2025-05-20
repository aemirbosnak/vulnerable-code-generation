//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void enqueue(struct Queue *Q, int element) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;
    if (Q->front == NULL) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    printf("\n%d enqueued to the queue", element);
}

int dequeue(struct Queue *Q) {
    int element;
    struct Node *temp = Q->front;
    if (Q->front == NULL) {
        printf("\nQueue is empty");
        return -1;
    } else if (Q->front == Q->rear) {
        element = Q->front->data;
        free(Q->front);
        Q->front = NULL;
        Q->rear = NULL;
    } else {
        element = Q->front->data;
        Q->front = Q->front->next;
        free(temp);
    }
    printf("\n%d dequeued from the queue", element);
    return element;
}

void display(struct Queue *Q) {
    struct Node *temp = Q->front;
    if (Q->front == NULL) {
        printf("\nQueue is empty");
    } else {
        printf("\nElements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    struct Queue Q;
    Q.front = NULL;
    Q.rear = NULL;
    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    enqueue(&Q, 40);
    enqueue(&Q, 50);
    display(&Q);
    dequeue(&Q);
    dequeue(&Q);
    display(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    printf("\n");
    return 0;
}