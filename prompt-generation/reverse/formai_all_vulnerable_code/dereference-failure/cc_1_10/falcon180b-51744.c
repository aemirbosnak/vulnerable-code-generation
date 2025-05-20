//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void *data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue *create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool is_empty(Queue *q) {
    return q->front == NULL;
}

bool is_full(Queue *q) {
    return q->size == 1000; // futuristic limit
}

void enqueue(Queue *q, void *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

void *dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    void *data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

void display(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = q->front;
    while (temp!= NULL) {
        printf("%p ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = create_queue();
    enqueue(q, "Hello");
    enqueue(q, "World");
    display(q);
    void *data = dequeue(q);
    printf("%s\n", (char *)data);
    display(q);
    return 0;
}