//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: authentic
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
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->tail == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (q->head == NULL) {
        return -1;
    }
    struct Node* temp = q->head;
    int data = temp->data;
    q->head = temp->next;
    free(temp);
    return data;
}

void printQueue(struct Queue* q) {
    struct Node* current = q->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printQueue(q);
    return 0;
}