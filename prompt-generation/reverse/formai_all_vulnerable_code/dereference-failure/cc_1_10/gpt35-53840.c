//FormAI DATASET v1.0 Category: Queue ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5       // Queue size

typedef struct {
    int front, rear;
    int items[SIZE];
} Queue;

Queue* createQueue();
void enqueue(Queue* q, int);
int dequeue(Queue* q);
void display(Queue* q);

int main() {
    Queue* q = createQueue();
    int choice, x;

    do {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(q, x);
                break;
            case 2:
                x = dequeue(q);
                printf("\nThe dequeued element is: %d", x);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 4);

    return 0;
}

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == SIZE-1) {
        printf("\nQueue is full!");
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("\n%d has been enqueued to the queue.", value);
    }
}

int dequeue(Queue* q) {
    int element;
    if (q->front == -1) {
        printf("\nQueue is empty!");
        return (-1);
    }
    else {
        element = q->items[q->front];
        if (q->front >= q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        else {
            q->front++;
        }
    }
    return element;
}

void display(Queue* q) {
    int i;
    if (q->front == -1) {
        printf("\nQueue is empty!");
    }
    else {
        printf("\nQueue items are: ");
        for(i = q->front; i <= q->rear; ++i) {
            printf("%d ", q->items[i]);
        }
    }
}