//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
};

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->tail == NULL) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (q->head == NULL) {
        return -1;
    }
    int data = q->head->data;
    struct Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
    return data;
}

int isEmpty(struct Queue* q) {
    return q->head == NULL;
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue is empty: %s\n", isEmpty(q)? "Yes" : "No");
    return 0;
}