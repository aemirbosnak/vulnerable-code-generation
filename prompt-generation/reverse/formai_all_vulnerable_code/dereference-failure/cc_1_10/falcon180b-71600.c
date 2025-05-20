//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
    int count;
};

// Function to create an empty queue
void createQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    if (q->count == MAX_SIZE) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->count++;
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* q) {
    int value = -1;
    struct Node* temp = q->front;

    if (!isEmpty(q)) {
        value = q->front->data;
        q->front = q->front->next;
        free(temp);
        q->count--;
    }

    return value;
}

// Function to display the elements in the queue
void display(struct Queue* q) {
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue are:\n");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("After adding 4 elements:\n");
    display(&q);

    int value = dequeue(&q);
    printf("Element removed from the queue: %d\n", value);

    printf("After removing an element:\n");
    display(&q);

    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("After adding 2 more elements:\n");
    display(&q);

    return 0;
}