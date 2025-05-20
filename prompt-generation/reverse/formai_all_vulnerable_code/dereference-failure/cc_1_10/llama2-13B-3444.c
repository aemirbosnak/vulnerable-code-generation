//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MIN_LENGTH 10

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

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        int data = rand() % 100;
        enqueue(q, data);
    }

    for (int i = 0; i < 100; i++) {
        int data = dequeue(q);
        if (data == -1) {
            break;
        }
        printf("%d ", data);
    }

    if (search(q, 42)) {
        printf("Found 42!\n");
    } else {
        printf("Not found\n");
    }

    return 0;
}