//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

Queue *create_queue() {
    Queue *new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

int is_empty(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(queue)) {
        queue->front = new_node;
    } else {
        queue->rear->next = new_node;
    }
    queue->rear = new_node;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void print_queue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
    } else {
        Node *temp = queue->front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    Queue *queue = create_queue();
    for (int i = 0; i < 10; i++) {
        int r = rand() % 100;
        enqueue(queue, r);
    }
    printf("Original queue:\n");
    print_queue(queue);
    int dequeued_data = dequeue(queue);
    printf("Dequeued data: %d\n", dequeued_data);
    printf("Queue after dequeue:\n");
    print_queue(queue);
    return 0;
}