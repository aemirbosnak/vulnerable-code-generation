//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct queue {
    node_t* head;
    node_t* tail;
} queue_t;

queue_t* create_queue() {
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(queue_t* queue, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

int dequeue(queue_t* queue) {
    node_t* temp = queue->head;
    int data = temp->data;
    if (temp->next == NULL) {
        free(temp);
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = temp->next;
        free(temp);
    }
    return data;
}

bool is_empty(queue_t* queue) {
    return (queue->head == NULL);
}

void free_queue(queue_t* queue) {
    while (!is_empty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    queue_t* queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    if (is_empty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
    free_queue(queue);
    return 0;
}