//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;
node_t *tail = NULL;

int is_empty() {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int is_full() {
    if (tail == NULL) {
        return 0;
    } else if (tail->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty()) {
        head = new_node;
        tail = new_node;
    } else if (is_full()) {
        printf("Queue is full\n");
    } else {
        tail->next = new_node;
        tail = tail->next;
    }
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is empty\n");
    } else if (head == tail) {
        node_t *temp_node = head;
        head = NULL;
        tail = NULL;
        free(temp_node);
    } else {
        node_t *temp_node = head;
        head = head->next;
        free(temp_node);
    }
}

void print_queue() {
    if (is_empty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        node_t *temp_node = head;
        while (temp_node!= NULL) {
            printf("%d ", temp_node->data);
            temp_node = temp_node->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);

    print_queue();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    print_queue();

    return 0;
}