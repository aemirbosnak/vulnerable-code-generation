//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    char name[50];
} Customer;

typedef struct {
    Customer queue[MAX];
    int front, rear;
} BookshopQueue;

// Function to create a queue
BookshopQueue* createQueue() {
    BookshopQueue* q = (BookshopQueue*)malloc(sizeof(BookshopQueue));
    q->front = q->rear = -1;
    return q;
}

// Check if the queue is full
int isFull(BookshopQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Check if the queue is empty
int isEmpty(BookshopQueue* q) {
    return q->front == -1;
}

// Add a customer to the queue
void enqueue(BookshopQueue* q, char* name) {
    if (isFull(q)) {
        printf("Oh no! The queue is full! '%s' has to wait for a moment.\n", name);
        return;
    }
    
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    strcpy(q->queue[q->rear].name, name);
    printf("Wow! '%s' has joined the queue. Position: %d\n", name, q->rear + 1);
}

// Remove a customer from the queue
void dequeue(BookshopQueue* q) {
    if (isEmpty(q)) {
        printf("Oh dear! There's no one to serve right now!\n");
        return;
    }

    printf("Yay! '%s' is being served!\n", q->queue[q->front].name);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Peek at the front customer of the queue
void peek(BookshopQueue* q) {
    if (isEmpty(q)) {
        printf("Oops! The queue is empty. No customers to peek at!\n");
    } else {
        printf("Currently serving: '%s'\n", q->queue[q->front].name);
    }
}

// Display the entire queue
void displayQueue(BookshopQueue* q) {
    if (isEmpty(q)) {
        printf("The queue is looking spare today! No customers in sight!\n");
        return;
    }

    printf("Current queue:\n");
    for (int i = 0; i < MAX; i++) {
        if (q->queue[i].name[0] != '\0') {
            printf("Position %d: '%s'\n", (i + 1), q->queue[i].name);
        }
    }
}

// Free the queue
void freeQueue(BookshopQueue* q) {
    free(q);
    printf("The magical bookshop queue has been freed from the realm of memory!\n");
}

// Main function to explore the queue
int main() {
    BookshopQueue* q = createQueue();
    
    enqueue(q, "Alice");
    enqueue(q, "Bob");
    enqueue(q, "Charlie");
    enqueue(q, "Diana");
    enqueue(q, "Eleanor");

    displayQueue(q);
    
    dequeue(q);
    peek(q);

    enqueue(q, "Finn");
    enqueue(q, "George");

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);  // Removing till empty

    displayQueue(q);
    freeQueue(q);

    return 0;
}