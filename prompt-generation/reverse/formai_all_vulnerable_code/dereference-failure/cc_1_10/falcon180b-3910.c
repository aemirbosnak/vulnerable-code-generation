//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int time_stamp;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* create_queue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;
    return new_queue;
}

void enqueue(Queue* queue, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->time_stamp = time(NULL);
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    Node* temp_node = queue->front;
    int data = temp_node->data;

    queue->front = temp_node->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp_node);
    queue->size--;

    return data;
}

void display(Queue* queue) {
    Node* temp_node = queue->front;

    if (temp_node == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }

    printf("\n");
}

int main() {
    Queue* queue = create_queue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    display(queue);

    int dequeued_data = dequeue(queue);
    printf("Dequeued element is: %d\n", dequeued_data);

    display(queue);

    return 0;
}