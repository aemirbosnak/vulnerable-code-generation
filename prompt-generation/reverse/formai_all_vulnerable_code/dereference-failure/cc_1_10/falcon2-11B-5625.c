//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct Queue {
    ListNode *front, *rear;
};

typedef struct Queue Queue;

void enqueue(Queue *q, int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int val = q->front->val;
    ListNode *node = q->front;
    q->front = q->front->next;
    free(node);

    return val;
}

bool is_empty(Queue *q) {
    return q->front == NULL;
}

void print_queue(Queue *q) {
    ListNode *curr = q->front;
    while (curr!= NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Queue *q = (Queue *)malloc(sizeof(Queue));

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    print_queue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    print_queue(q);

    return 0;
}