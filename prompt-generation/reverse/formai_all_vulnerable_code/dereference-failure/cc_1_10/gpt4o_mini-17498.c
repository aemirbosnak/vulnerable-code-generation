//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function Prototypes
Queue* createQueue();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int peek(Queue* q);
void display(Queue* q);
void freeQueue(Queue* q);

int main() {
    Queue* queue = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                value = peek(queue);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                display(queue);
                break;
            case 5:
                freeQueue(queue);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

bool isEmpty(Queue* q) {
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
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Error signal
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return item;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1; // Error signal
    }
    return q->items[q->front];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int count = (q->rear + MAX - q->front) % MAX + 1;
    for (int i = 0; i < count; i++) {
        int index = (q->front + i) % MAX;
        printf("%d ", q->items[index]);
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    free(q);
}