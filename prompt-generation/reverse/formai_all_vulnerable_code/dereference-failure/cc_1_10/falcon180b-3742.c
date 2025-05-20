//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

// Define the structure of the node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize the queue
void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int is_empty(Queue* q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

// Enqueue an element
void enqueue(Queue* q, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Dequeue an element
int dequeue(Queue* q) {
    Node* temp_node = q->front;
    int data = temp_node->data;

    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else if (q->front == q->rear) {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }

    return data;
}

// Display the contents of the queue
void display(Queue* q) {
    Node* temp_node = q->front;

    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}