//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process {
    char name[20];
    int burstTime;
    int arrivalTime;
    int priority;
};

struct node {
    struct process data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void enqueue(struct queue *q, struct process p) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = p;
    newNode->next = NULL;

    if (q->head == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

struct process dequeue(struct queue *q) {
    struct process p = q->head->data;
    struct node *temp = q->head;

    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);
    return p;
}

int main() {
    struct queue readyQueue;
    readyQueue.head = readyQueue.tail = NULL;

    struct process p1 = {"P1", 10, 0, 1};
    struct process p2 = {"P2", 5, 3, 2};
    struct process p3 = {"P3", 8, 6, 3};

    enqueue(&readyQueue, p1);
    enqueue(&readyQueue, p2);
    enqueue(&readyQueue, p3);

    int currentTime = 0;
    while (readyQueue.head != NULL) {
        struct process p = dequeue(&readyQueue);

        printf("%s %d\n", p.name, currentTime);

        currentTime += p.burstTime;
    }

    return 0;
}