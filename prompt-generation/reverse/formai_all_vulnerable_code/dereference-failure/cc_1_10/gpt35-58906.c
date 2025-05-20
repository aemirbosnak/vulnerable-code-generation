//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int front, rear;
    int items[MAX_SIZE];
} Queue;

Queue *createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue *q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(Queue *q) {
    if (q->rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Overflow!");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = element;
        printf("Added element: %d\n", element);
    }
}

int dequeue(Queue *q) {
    int element;
    if (isEmpty(q)) {
        printf("Underflow!");
        return (-1);
    } else {
        element = q->items[q->front];
        if (q->front >= q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        printf("Deleted element: %d\n", element);
        return (element);
    }
}

void display(Queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Nothing to display\n");
    } else {
        printf("Queue elements: ");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue *q = createQueue();
    int choice, element;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &element);
                enqueue(q, element);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}