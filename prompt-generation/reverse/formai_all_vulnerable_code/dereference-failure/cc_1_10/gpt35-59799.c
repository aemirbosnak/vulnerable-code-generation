//FormAI DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

/* Queue implementation using linked list */
typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;


/* Function to create a new node */
Node* newNode(int data) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/* Function to create a new queue */
Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

/* Function to insert an element at the end of the queue */
void enqueue(Queue *q, int data) {
    Node *temp = newNode(data);
    if(q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

/* Function to remove the element from the front of the queue */
int dequeue(Queue *q) {
    if(q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if(q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

/* Function to display the contents of the queue */
void display(Queue *q) {
    Node *temp = q->front;
    if(temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();

    /* Test enqueue and dequeue operations */
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    display(q);
    printf("Removed element: %d\n", dequeue(q));
    display(q);
    enqueue(q, 4);
    display(q);
    printf("Removed element: %d\n", dequeue(q));
    display(q);

    return 0;
}