//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

/* Queue structure */
typedef struct node {
    int data;
    struct node *next;
} node_t;

/* Queue */
typedef struct {
    node_t *front;
    node_t *rear;
    int size;
} queue_t;

/* Function to create a new node */
node_t *new_node(int value) {
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Function to create a queue */
queue_t *new_queue() {
    queue_t *newQueue = (queue_t*)malloc(sizeof(queue_t));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

/* Function to check if the queue is empty */
int is_empty(queue_t *queue) {
    return queue->front == NULL;
}

/* Function to get the size of the queue */
int get_size(queue_t *queue) {
    return queue->size;
}

/* Function to add a value to the back of the queue */
void enqueue(queue_t *queue, int value) {
    node_t *newNode = new_node(value);
    if (is_empty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
}

/* Function to remove a value from the front of the queue */
int dequeue(queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    int dequeued_value = queue->front->data;
    node_t *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return dequeued_value;
}

/* Function to display the queue */
void display(queue_t *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue:\n");
        node_t *temp = queue->front;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

/* Main function */
int main() {
    queue_t *queue = new_queue();
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    
    display(queue);
    
    printf("Dequeued value: %d\n", dequeue(queue));
    
    display(queue);
    
    printf("Queue size: %d\n", get_size(queue));
    
    return 0;
}