//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q) {
        q->head = NULL;
        q->tail = NULL;
        return q;
    }
    printf("\nError: Queue creation failed!\n");
    return NULL;
}

void enqueue(Queue* q, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(q->head == NULL && q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
        return;
    }
    q->tail->next = new_node;
    q->tail = new_node;
}

void dequeue(Queue* q) {
    if(q->head == NULL) {
        printf("\nError: Queue is empty!\n");
        return;
    }
    Node* temp = q->head;
    q->head = q->head->next;
    if(q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
}

void display(Queue* q) {
    printf("\nQueue: ");
    Node* temp = q->head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    enqueue(q, 50);
    enqueue(q, 60);

    display(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    display(q);

    return 0;
}