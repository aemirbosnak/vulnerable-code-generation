//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a knight in the queue
typedef struct Knight {
    int id;
    char name[50];
} Knight;

// Structure to represent the rear and front of the queue
typedef struct Queue {
    Knight knights[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Function to create a new queue for the knights
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->count == MAX_SIZE;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->count == 0;
}

// Function to add a new knight to the queue
void enqueue(Queue* queue, int id, const char* name) {
    if (isFull(queue)) {
        printf("Hark! The queue of knights is full! No more knights may enter!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->knights[queue->rear].id = id;
    snprintf(queue->knights[queue->rear].name, sizeof(queue->knights[queue->rear].name), "%s", name);
    queue->count++;
    printf("%s (Knight ID: %d) has entered the queue of valor!\n", name, id);
}

// Function to remove a knight from the queue
Knight dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Alas! The queue of knights is empty! No knight to dequeue!\n");
        Knight emptyKnight = { -1, "None" };
        return emptyKnight;
    }
    Knight knight = queue->knights[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;
    printf("%s (Knight ID: %d) has been summoned forth to battle!\n", knight.name, knight.id);
    return knight;
}

// Function to display knights currently in the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue of knights is but an empty space, awaiting brave souls!\n");
        return;
    }
    printf("The queue of brave knights:\n");
    for (int i = 0; i < queue->count; i++) {
        Knight knight = queue->knights[(queue->front + i) % MAX_SIZE];
        printf("Knight ID: %d, Name: %s\n", knight.id, knight.name);
    }
}

// Main function to demonstrate the queue of knights
int main() {
    Queue* knightQueue = createQueue();

    printf("Welcome to the Grand Tournament of Valor!\n");

    enqueue(knightQueue, 1, "Sir Lancelot");
    enqueue(knightQueue, 2, "Lady Guinevere");
    enqueue(knightQueue, 3, "Sir Gawain");

    displayQueue(knightQueue);

    dequeue(knightQueue);
    dequeue(knightQueue);

    displayQueue(knightQueue);

    enqueue(knightQueue, 4, "Sir Percival");
    enqueue(knightQueue, 5, "Robin the Brave");

    displayQueue(knightQueue);

    // Dequeuing all remaining knights
    while (!isEmpty(knightQueue)) {
        dequeue(knightQueue);
    }

    // Final display of the queue
    displayQueue(knightQueue);

    // Free the queue memory
    free(knightQueue);

    printf("The Grand Tournament has concluded. Thank you for your valor!\n");
    return 0;
}