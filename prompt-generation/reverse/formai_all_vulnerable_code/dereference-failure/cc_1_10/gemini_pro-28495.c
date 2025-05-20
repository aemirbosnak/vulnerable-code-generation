//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
    int size;
} queue_t;

queue_t *create_queue() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(queue_t *queue, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

int dequeue(queue_t *queue) {
    if (queue->front == NULL) {
        return -1;
    }

    int data = queue->front->data;
    node_t *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    queue->size--;

    return data;
}

int is_empty(queue_t *queue) {
    return queue->size == 0;
}

void print_queue(queue_t *queue) {
    node_t *current = queue->front;

    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    queue_t *queue = create_queue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    print_queue(queue);

    int data = dequeue(queue);
    if (data != -1) {
        printf("Dequeued: %d\n", data);
    } else {
        printf("Queue is empty\n");
    }

    print_queue(queue);

    return 0;
}