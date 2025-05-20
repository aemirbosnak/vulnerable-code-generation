//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void enqueue(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int dequeue() {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = head->data;
    struct node *temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) {
        tail = NULL;
    }

    return data;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    printf("Queue size: %d\n", (int)sizeof(head));

    return 0;
}