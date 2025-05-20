//FormAI DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure of Queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int capacity;
    int count;
} Queue;

// Function to create queue
Queue* createQueue(int capacity) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->count = 0;
    q->rear = -1;
    return q;
}

// Function to check if queue is full
int isFull(Queue* q) {
    return q->count == q->capacity;
}

// Function to check if queue is empty
int isEmpty(Queue* q) {
    return q->count == 0;
}

// Function to add element to the queue
void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("\nQueue is full");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = data;
    q->count++;
}

// Function to remove element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty");
        return -1;
    }
    int data = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->count--;
    return data;
}

// Function to display all elements in the queue
void display(Queue* q) {
    int i;
    if (isEmpty(q)) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nElements in Queue: ");
    for (i = 0; i < q->count; i++) {
        printf("%d ", q->arr[(q->front + i) % q->capacity]);
    }
}


/* Main Function */
int main() {
    int choice, data;
    Queue* q = createQueue(MAX_SIZE);

    printf("\nC Queue Implementation Example\n");

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                data = dequeue(q);
                if (data != -1)
                    printf("Removed element: %d", data);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}