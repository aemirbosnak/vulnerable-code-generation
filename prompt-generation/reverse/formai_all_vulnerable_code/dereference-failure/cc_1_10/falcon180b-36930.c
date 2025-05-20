//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void* data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

queue* create_queue() {
    queue* new_queue = (queue*) malloc(sizeof(queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

bool is_empty(queue* q) {
    return q->front == NULL;
}

void enqueue(queue* q, void* data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

void* dequeue(queue* q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }

    node* temp_node = q->front;
    void* data = temp_node->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp_node);
    return data;
}

void print_queue(queue* q) {
    node* current_node = q->front;
    while (current_node!= NULL) {
        printf("%p ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    queue* q = create_queue();

    enqueue(q, (void*) 1);
    enqueue(q, (void*) 2);
    enqueue(q, (void*) 3);

    print_queue(q);

    void* data = dequeue(q);
    printf("Dequeued data: %p\n", data);

    print_queue(q);

    return 0;
}