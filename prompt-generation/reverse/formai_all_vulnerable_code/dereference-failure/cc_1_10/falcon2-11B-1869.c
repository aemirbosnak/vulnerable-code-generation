//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* head;
    struct node* tail;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue(struct queue* queue, int data) {
    struct node* node = newNode(data);

    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

void dequeue(struct queue* queue) {
    if (queue->head == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
}

void printQueue(struct queue* queue) {
    struct node* temp = queue->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    printQueue(queue);

    dequeue(queue);

    printQueue(queue);

    free(queue);

    return 0;
}