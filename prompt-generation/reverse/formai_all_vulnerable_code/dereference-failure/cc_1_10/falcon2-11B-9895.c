//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
    int size;
} queue;

void enqueue(queue *q, int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
        q->size++;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
        q->size++;
    }
}

int dequeue(queue *q) {
    if (q->size == 0) {
        return -1;
    }
    node *temp = q->head;
    if (q->size == 1) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
    }
    free(temp);
    q->size--;
    return temp->data;
}

void print_queue(queue *q) {
    node *temp = q->head;
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;
    srand(time(NULL));
    int data;
    for (int i = 0; i < MAX_SIZE; i++) {
        data = rand() % 10;
        enqueue(&q, data);
    }
    print_queue(&q);
    data = dequeue(&q);
    while (data!= -1) {
        printf("%d ", data);
        data = dequeue(&q);
    }
    printf("\n");
    return 0;
}