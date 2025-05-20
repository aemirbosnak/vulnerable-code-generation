//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
    int size;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->head->data;
    struct Node* temp = q->head;
    q->head = q->head->next;
    q->size--;
    free(temp);
    return data;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->head->data;
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Queue size: %d\n", q->size);
    printf("Front element: %d\n", peek(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Queue size after dequeuing: %d\n", q->size);
    return 0;
}