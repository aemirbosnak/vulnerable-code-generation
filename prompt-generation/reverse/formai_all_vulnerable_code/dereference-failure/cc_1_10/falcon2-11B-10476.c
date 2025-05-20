//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node
struct node
{
    int data;
    struct node* next;
};

// Structure to represent the queue
struct queue
{
    struct node* head;
    struct node* tail;
};

// Function to add elements to the queue
void enqueue(struct queue* q, int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->tail == NULL)
    {
        q->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

// Function to remove elements from the queue
int dequeue(struct queue* q)
{
    if (q->head == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->head->data;
    struct node* temp = q->head;
    q->head = q->head->next;

    if (q->head == NULL)
    {
        q->tail = NULL;
    }

    free(temp);
    return data;
}

// Function to check if the queue is empty
int is_empty(struct queue* q)
{
    return (q->head == NULL);
}

// Function to check if the queue is full
int is_full(struct queue* q)
{
    return (q->tail == q->head);
}

// Function to print the contents of the queue
void print_queue(struct queue* q)
{
    struct node* temp = q->head;

    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;

    // Enqueue elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Dequeue elements
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));

    print_queue(q);

    return 0;
}