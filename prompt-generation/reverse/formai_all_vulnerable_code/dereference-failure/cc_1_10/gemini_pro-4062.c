//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *head;
    node_t *tail;
    int size;
} queue_t;

queue_t *create_queue() {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void destroy_queue(queue_t *queue) {
    while (queue->head != NULL) {
        node_t *next = queue->head->next;
        free(queue->head);
        queue->head = next;
    }
    free(queue);
}

int enqueue(queue_t *queue, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }

    queue->size++;
    return 0;
}

int dequeue(queue_t *queue) {
    if (queue->head == NULL) {
        return -1;
    }

    int data = queue->head->data;
    node_t *next = queue->head->next;
    free(queue->head);
    queue->head = next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    queue->size--;
    return data;
}

int front(queue_t *queue) {
    if (queue->head == NULL) {
        return -1;
    }

    return queue->head->data;
}

int back(queue_t *queue) {
    if (queue->tail == NULL) {
        return -1;
    }

    return queue->tail->data;
}

int size(queue_t *queue) {
    return queue->size;
}

int is_empty(queue_t *queue) {
    return queue->size == 0;
}

void print_queue(queue_t *queue) {
    node_t *current = queue->head;
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

    dequeue(queue);
    dequeue(queue);

    print_queue(queue);

    printf("Front: %d\n", front(queue));
    printf("Back: %d\n", back(queue));
    printf("Size: %d\n", size(queue));
    printf("Is empty: %d\n", is_empty(queue));

    destroy_queue(queue);

    return 0;
}