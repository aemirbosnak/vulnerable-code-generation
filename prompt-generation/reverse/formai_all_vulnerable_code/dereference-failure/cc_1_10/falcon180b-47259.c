//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
    int size;
} queue;

// Function to create an empty queue
void create_queue(queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Function to check if the queue is empty
bool is_empty(queue* q) {
    return q->front == NULL && q->rear == NULL;
}

// Function to check if the queue is full
bool is_full(queue* q) {
    return q->size == MAX_SIZE;
}

// Function to enqueue an element
void enqueue(queue* q, int value) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = value;
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

// Function to dequeue an element
int dequeue(queue* q) {
    int value = -1;

    if (!is_empty(q)) {
        node* temp_node = q->front;
        value = temp_node->data;
        q->front = temp_node->next;

        if (q->front == NULL) {
            q->rear = NULL;
        }

        free(temp_node);
        q->size--;
    }

    return value;
}

// Function to display the elements in the queue
void display(queue* q) {
    node* temp_node = q->front;

    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue are: ");

        while (temp_node!= NULL) {
            printf("%d ", temp_node->data);
            temp_node = temp_node->next;
        }

        printf("\n");
    }
}

int main() {
    queue q;
    create_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    int dequeued_value = dequeue(&q);
    printf("Dequeued value: %d\n", dequeued_value);

    display(&q);

    return 0;
}