//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

void init_queue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(Queue *q) {
    if (q->head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->head->data;
    Node *temp = q->head;
    q->head = q->head->next;
    free(temp);

    if (q->head == NULL) {
        q->tail = NULL;
    }

    return data;
}

void print_queue(Queue *q) {
    Node *temp = q->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue my_queue;
    init_queue(&my_queue);

    enqueue(&my_queue, 1);
    enqueue(&my_queue, 2);
    enqueue(&my_queue, 3);
    enqueue(&my_queue, 4);
    enqueue(&my_queue, 5);

    printf("Queue before dequeue: ");
    print_queue(&my_queue);

    printf("\nDequeued: %d\n", dequeue(&my_queue));

    printf("Queue after dequeue: ");
    print_queue(&my_queue);

    return 0;
}