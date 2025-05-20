//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
    int size;
} Queue;

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->head == NULL) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (q->head == NULL) {
        return -1;
    }
    Node* temp = q->head;
    q->head = q->head->next;
    q->size--;
    free(temp);
    return temp->data;
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);

    printf("Queue elements: ");
    while (q->head!= NULL) {
        printf("%d ", dequeue(q));
    }

    printf("\nSize of the queue: %d\n", q->size);

    return 0;
}