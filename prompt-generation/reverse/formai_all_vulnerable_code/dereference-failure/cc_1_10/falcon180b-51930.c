//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure for the queue
struct node {
    int data;
    struct node* next;
};

// Queue structure
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
struct queue* create_queue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int is_empty(struct queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is full
int is_full(struct queue* q) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        return 1;
    } else {
        free(temp);
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(struct queue* q, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    int data;
    struct node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
        return data;
    }
}

// Function to display the elements in the queue
void display(struct queue* q) {
    struct node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct queue* q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}