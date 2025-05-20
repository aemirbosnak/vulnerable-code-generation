//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    int size;
};

// Function to create a new queue
struct queue* create(void) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->size = 0;
    return q;
}

// Function to enqueue a new element
void enqueue(struct queue* q, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = newNode;
    } else {
        struct node* current = q->front;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    q->size++;
}

// Function to dequeue an element
int dequeue(struct queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    struct node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

// Function to check if queue is empty
int is_empty(struct queue* q) {
    return q->size == 0;
}

// Function to check if queue is full
int is_full(struct queue* q) {
    return q->size == 10;
}

// Function to peek at front of queue
int peek(struct queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Function to print queue
void print(struct queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    struct node* current = q->front;
    printf("Queue contents: ");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct queue* q = create();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Front element: %d\n", peek(q));
    printf("Dequeued element: %d\n", dequeue(q));
    print(q);
    printf("Dequeued element: %d\n", dequeue(q));
    print(q);
    printf("Dequeued element: %d\n", dequeue(q));
    print(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Queue is empty: %d\n", is_empty(q));
    printf("Queue is full: %d\n", is_full(q));
    return 0;
}