//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicating empty queue
    }

    int element = q->items[q->front];

    if (q->front == q->rear) {
        q->front = -1; 
        q->rear = -1; 
    } else {
        q->front = (q->front + 1) % MAX;
    }
    
    printf("Dequeued %d\n", element);
    return element;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d", q->items[i]); // print the last element
    printf("\n");
}

void deleteQueue(Queue* q) {
    free(q);
    printf("Queue deleted successfully.\n");
}

int main() {
    Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                deleteQueue(q);
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}