//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};

struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(struct Queue *queue, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

int dequeue(struct Queue *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    int data = queue->head->data;
    struct Node *temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    return data;
}

int peek(struct Queue *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    return queue->head->data;
}

int isEmpty(struct Queue *queue) {
    return queue->head == NULL;
}

void printQueue(struct Queue *queue) {
    struct Node *temp = queue->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    printQueue(queue);

    return 0;
}