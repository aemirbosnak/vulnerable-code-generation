//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_NAME 20
#define MAX_QUEUE 10

typedef struct {
    char name[MAX_NAME];
    int weight;
} Baggage;

typedef struct {
    Baggage *bags[MAX_QUEUE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE == q->front;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, Baggage *baggage) {
    if (isFull(q)) {
        printf("Queue is full! A raider stole a bag!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->bags[q->rear] = baggage;
    printf("Bag %s (weight %d) added to the queue.\n", baggage->name, baggage->weight);
}

Baggage *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to process.\n");
        return NULL;
    }
    Baggage *baggage = q->bags[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE;
    }
    printf("Processing bag %s (weight %d)... ", baggage->name, baggage->weight);
    return baggage;
}

void handleBaggage(Queue *q) {
    for (int i = 0; i < MAX_BAGS; i++) {
        sleep(1);
        if (rand() % 2 == 0) { // Randomly either add or process
            Baggage *newBag = (Baggage *)malloc(sizeof(Baggage));
            snprintf(newBag->name, sizeof(newBag->name), "Bag_%d", i + 1);
            newBag->weight = (rand() % 20) + 1; // Weight between 1-20
            enqueue(q, newBag);
        } else {
            Baggage *bag = dequeue(q);
            if (bag != NULL) {
                printf("Done processing bag %s (weight %d).\n", bag->name, bag->weight);
                free(bag);
            }
        }
        if (rand() % 10 == 0) {
            printf("An unexpected event occurred! Looters have arrived!\n");
            while (!isEmpty(q)) {
                Baggage *bag = dequeue(q);
                if (bag != NULL) {
                    printf("Looter took bag %s (weight %d).\n", bag->name, bag->weight);
                    free(bag);
                }
            }
            printf("All bags are gone, retreating...\n");
            break;
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    Queue baggageQueue;
    initQueue(&baggageQueue);
    
    printf("Welcome to the Post-Apocalyptic Airport Baggage Handling Simulation!\n");
    printf("Managing baggage in a world where time has stood still...\n\n");
    
    handleBaggage(&baggageQueue);
    
    printf("Simulation ended. Remaining bags in the queue: %d\n", baggageQueue.rear - baggageQueue.front + 1);

    while (!isEmpty(&baggageQueue)) {
        Baggage *bag = dequeue(&baggageQueue);
        if (bag != NULL) {
            free(bag);
        }
    }
    
    return 0;
}