//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// structure for a node
struct node {
    int data;
    struct node* link;
};

// structure for a queue
struct queue {
    struct node* front;
    struct node* rear;
};

// function to create an empty queue
void create(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// function to check if the queue is empty
int is_empty(struct queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// function to add an element to the rear of the queue
void enqueue(struct queue* q, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

// function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    int data;
    struct node* temp = q->front;

    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        data = temp->data;
        q->front = temp->link;
        free(temp);
    }

    return data;
}

// function to display the elements in the queue
void display(struct queue* q) {
    struct node* temp = q->front;

    if (is_empty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

// main function
int main() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    create(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    return 0;
}