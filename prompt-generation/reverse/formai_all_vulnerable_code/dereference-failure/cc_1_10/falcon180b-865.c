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
    int size;
} queue_t;

queue_t* create_queue() {
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

bool is_empty(queue_t* q) {
    return q->head == NULL;
}

int get_size(queue_t* q) {
    return q->size;
}

void enqueue(queue_t* q, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->size++;
}

int dequeue(queue_t* q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = q->head->data;
    node_t* temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->size--;
    return data;
}

int peek(queue_t* q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return q->head->data;
}

void print_queue(queue_t* q) {
    node_t* curr_node = q->head;
    printf("Queue: ");
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main() {
    queue_t* q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    print_queue(q);
    int front_elem = peek(q);
    printf("Front element: %d\n", front_elem);
    dequeue(q);
    print_queue(q);
    dequeue(q);
    dequeue(q);
    printf("Queue is empty: %s\n", is_empty(q)? "true" : "false");
    free(q);
    return 0;
}