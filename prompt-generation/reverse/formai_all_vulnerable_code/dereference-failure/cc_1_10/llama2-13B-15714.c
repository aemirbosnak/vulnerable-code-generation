//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 100000
#define M 100

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void init_queue(struct queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(struct queue *q, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
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

int dequeue(struct queue *q) {
    int data = q->head->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(q->head);
    return data;
}

void benchmark(struct queue *q) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            enqueue(q, j);
        }
        for (j = 0; j < M; j++) {
            dequeue(q);
        }
    }
}

int main() {
    struct queue q;
    init_queue(&q);

    clock_t start, end;
    double elapsed;

    start = clock();
    benchmark(&q);
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Benchmarking queue with %d elements and %d operations per element\n", N, M);
    printf("Elapsed time: %f seconds\n", elapsed);

    return 0;
}