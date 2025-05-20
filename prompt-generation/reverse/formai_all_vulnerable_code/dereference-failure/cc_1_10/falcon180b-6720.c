//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

Queue *enqueue(Queue *front, Queue *rear, int data) {
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    return front;
}

Queue *dequeue(Queue *front, Queue *rear) {
    Queue *temp = front;

    if (front == NULL)
        return NULL;

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        while (temp->next!= rear) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = rear;
        rear = temp;
    }

    return front;
}

void display(Queue *front) {
    Queue *temp = front;

    if (front == NULL)
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue *front = NULL, *rear = NULL;

    front = enqueue(front, rear, 10);
    front = enqueue(front, rear, 20);
    front = enqueue(front, rear, 30);
    display(front);

    front = dequeue(front, rear);
    display(front);

    front = dequeue(front, rear);
    display(front);

    front = dequeue(front, rear);
    display(front);

    return 0;
}