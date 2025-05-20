//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define N 100

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* head;
    struct node* tail;
};

void enqueue(struct queue* q, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
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

int dequeue(struct queue* q) {
    int data = q->head->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(q->head);
    return data;
}

int main() {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));

    for (int i = 0; i < N; i++) {
        enqueue(q, i);
    }

    for (int i = 0; i < N; i++) {
        int data = dequeue(q);
        printf("%d ", data);
    }

    return 0;
}