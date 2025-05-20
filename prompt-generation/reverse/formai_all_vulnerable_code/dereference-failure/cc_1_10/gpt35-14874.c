//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CAPACITY 50
#define MAX_WEIGHT 100
#define MIN_WAIT_TIME 2
#define MAX_WAIT_TIME 10

typedef struct node {
    int weight;
    struct node *next;
} Node;

typedef struct {
    int size;
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
}

bool isQueueEmpty(Queue *q) {
    return (q->size == 0);
}

int getQueueSize(Queue *q) {
    return q->size;
}

void enqueue(Queue *q, int weight) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Out of Memory!\n");
        exit(1);
    }
    newNode->weight = weight;
    newNode->next = NULL;
    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int weight = q->front->weight;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return weight;
}

int main() {
    srand(time(NULL));  // Setting seed for random number generator
    Queue conveyorBelt, baggageClaim;
    initQueue(&conveyorBelt);
    initQueue(&baggageClaim);
    int capacity = rand() % MAX_CAPACITY + 1;  // Picking a random value between 1 and MAX_CAPACITY
    int totalWeight = 0, numBags = 0, waitTime = 0;
    bool isBusy = false;
    printf("Airport Baggage Handling Simulation:\n");
    printf("Capacity of Conveyor Belt: %d\n", capacity);
    printf("--------------------------------------------------\n");
    while (true) {
        if (isBusy) {
            if (waitTime == 0) {
                totalWeight -= dequeue(&conveyorBelt);
                isBusy = false;
            } else {
                waitTime--;
            }
        } else {
            if (!isQueueEmpty(&conveyorBelt)) {
                numBags--;
                isBusy = true;
                waitTime = rand() % (MAX_WAIT_TIME - MIN_WAIT_TIME + 1) + MIN_WAIT_TIME;
                printf("Baggage is being moved to baggage claim... \n");
            }
        }
        if (!isQueueEmpty(&baggageClaim)) {
            printf("Baggage is being taken by passengers... \n");
            dequeue(&baggageClaim);
        }
        if (numBags < capacity) {
            int weight = rand() % MAX_WEIGHT + 1;  // Picking a random value between 1 and MAX_WEIGHT
            printf("A Bag of weight %d is being added to the conveyor belt... \n", weight);
            enqueue(&conveyorBelt, weight);
            totalWeight += weight;
            numBags++;
        }
        if (!isBusy && isQueueEmpty(&conveyorBelt) && isQueueEmpty(&baggageClaim)) {
            printf("All baggage has been processed.\n");
            break;
        }
        if (totalWeight >= capacity) {
            printf("Conveyor belt is full. Moving baggage to baggage claim... \n");
            while(!isQueueEmpty(&conveyorBelt)) {
                enqueue(&baggageClaim, dequeue(&conveyorBelt));
            }
        }
    }
    printf("--------------------------------------------------\n");
    printf("Simulation complete!\n");
    return 0;
}