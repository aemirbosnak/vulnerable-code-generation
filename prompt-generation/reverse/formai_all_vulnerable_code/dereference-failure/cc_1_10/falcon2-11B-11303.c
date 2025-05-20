//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
// This is a unique C Queue Implementation program in a Cyberpunk style.
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} Queue;

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = newNode;
        q->size++;
        return;
    }

    q->tail->next = newNode;
    q->tail = newNode;
    q->size++;
}

int dequeue(Queue* q) {
    if (q->size == 0) {
        return -1;
    }

    int data = q->head->data;
    Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->size--;
    return data;
}

void printQueue(Queue* q) {
    Node* node = q->head;
    printf("Queue: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printQueue(q);

    printf("Dequeued: %d\n", dequeue(q));

    printQueue(q);

    return 0;
}