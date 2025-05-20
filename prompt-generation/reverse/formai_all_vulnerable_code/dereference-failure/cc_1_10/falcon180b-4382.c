//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *create_queue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if(q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int is_empty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if(is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(Queue *q) {
    if(is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

int peek(Queue *q) {
    if(is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

void display(Queue *q) {
    if(is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    Node *temp = q->front;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int dequeued_data = dequeue(q);
    printf("Dequeued: %d\n", dequeued_data);
    display(q);
    int peeked_data = peek(q);
    printf("Peeked: %d\n", peeked_data);
    return 0;
}