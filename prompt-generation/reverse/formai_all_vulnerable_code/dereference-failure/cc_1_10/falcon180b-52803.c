//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

/* Node structure definition */
struct node {
    int data;
    struct node* next;
};

/* Queue structure definition */
struct queue {
    struct node* front;
    struct node* rear;
};

/* Function to create an empty queue */
struct queue* create_queue(void) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

/* Function to check if the queue is empty */
int is_empty(struct queue* q) {
    return q->front == NULL;
}

/* Function to add an element to the rear of the queue */
void enqueue(struct queue* q, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

/* Function to remove an element from the front of the queue */
int dequeue(struct queue* q) {
    int value;
    struct node* temp = q->front;

    if (is_empty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }

    value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return value;
}

/* Function to display the elements of the queue */
void display(struct queue* q) {
    struct node* temp = q->front;

    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    int value = dequeue(q);
    printf("Dequeued value is: %d\n", value);

    display(q);

    return 0;
}