//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Queue node structure
struct queue {
    struct node* head;
    struct node* tail;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new queue
struct queue* create_queue() {
    struct queue* new_queue = (struct queue*) malloc(sizeof(struct queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

// Function to add an element to the queue
void enqueue(struct queue* q, int data) {
    struct node* new_node = create_node(data);
    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

// Function to delete an element from the queue
void delete_element(struct queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty\n");
    } else {
        q->head = q->head->next;
        free(q->tail);
        q->tail = NULL;
    }
}

// Function to print the elements of the queue
void print_queue(struct queue* q) {
    struct node* temp = q->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the queue is empty
int is_empty(struct queue* q) {
    if (q->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is full
int is_full(struct queue* q) {
    if (q->head == NULL) {
        return 0;
    } else {
        return 1;
    }
}

// Main function
int main() {
    struct queue* q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print_queue(q);
    delete_element(q);
    print_queue(q);
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
    if (is_full(q)) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
    return 0;
}