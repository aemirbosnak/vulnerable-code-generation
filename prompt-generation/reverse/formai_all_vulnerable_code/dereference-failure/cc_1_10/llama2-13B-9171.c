//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 100
#define M 10
#define MAGIC_NUMBER 42

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* head;
    struct node* tail;
};

void init_queue(struct queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

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
    if (q->head == NULL) {
        return -1;
    }

    int data = q->head->data;
    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(q->head);
    return data;
}

int search(struct queue* q, int data) {
    struct node* current = q->head;

    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

int main() {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    init_queue(q);

    for (int i = 0; i < N; i++) {
        int data = (i % M) * (i % M) % MAGIC_NUMBER;
        enqueue(q, data);
    }

    for (int i = 0; i < N; i++) {
        int data = dequeue(q);
        if (data == -1) {
            break;
        }

        printf("%d\n", data);
    }

    int found = search(q, MAGIC_NUMBER);
    if (found) {
        printf("Found %d in the queue!\n", MAGIC_NUMBER);
    } else {
        printf("Did not find %d in the queue.\n", MAGIC_NUMBER);
    }

    return 0;
}