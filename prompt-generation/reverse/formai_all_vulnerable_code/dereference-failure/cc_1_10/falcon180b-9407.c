//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
struct node {
    int data;
    struct node *next;
};

// Define the structure of the queue
struct queue {
    struct node *front;
    struct node *rear;
};

// Function to create a new node with given data
struct node *create_node(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new empty queue
struct queue *create_queue() {
    struct queue *new_queue = (struct queue*) malloc(sizeof(struct queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// Function to check if the queue is empty
int is_empty(struct queue *queue) {
    if (queue->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to enqueue an element into the queue
void enqueue(struct queue *queue, int data) {
    struct node *new_node = create_node(data);
    if (is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *queue) {
    int data;
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        struct node *temp = queue->front;
        data = temp->data;
        queue->front = temp->next;
        free(temp);
        if (is_empty(queue)) {
            queue->rear = NULL;
        }
        return data;
    }
}

// Function to display the elements in the queue
void display(struct queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
    } else {
        struct node *temp = queue->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct queue *queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    int dequeued_data = dequeue(queue);
    printf("Dequeued data: %d\n", dequeued_data);
    display(queue);
    return 0;
}