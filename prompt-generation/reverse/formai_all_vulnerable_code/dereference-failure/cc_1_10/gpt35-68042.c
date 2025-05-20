//FormAI DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(Queue* q) {
    if (q->head == NULL) {
        return -1;
    } else {
        int data = q->head->data;
        Node* temp = q->head;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        free(temp);
        return data;
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}