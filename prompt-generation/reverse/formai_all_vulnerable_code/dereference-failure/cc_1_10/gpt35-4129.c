//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_WEIGHT 50
#define MAX_FLIGHTS 20

/* Function to generate random integers */
int random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

/* Baggage struct */
typedef struct {
    int weight;
    int flightNum;
} Baggage;

/* Baggage queue */
typedef struct {
    Baggage* heap[MAX_BAGGAGE];
    int size;
} Queue;

/* Function to initialize a queue */
Queue* init_queue()
{
    Queue* queue = malloc(sizeof(Queue));
    queue->size = 0;
    return queue;
}

/* Function to add baggage to queue */
void enqueue(Queue* queue, Baggage* baggage)
{
    int i = queue->size;
    while (i > 0 && queue->heap[(i - 1) / 2]->flightNum < baggage->flightNum) {
        queue->heap[i] = queue->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->heap[i] = baggage;
    queue->size++;
}

/* Function to remove baggage from queue */
Baggage* dequeue(Queue* queue)
{
    Baggage* baggage = queue->heap[0];
    queue->size--;
    int i = 0;
    while (i * 2 + 1 < queue->size) {
        int maxChild = i * 2 + 1;
        if (i * 2 + 2 < queue->size && queue->heap[i * 2 + 2]->flightNum > queue->heap[maxChild]->flightNum) {
            maxChild = i * 2 + 2;
        }
        if (queue->heap[maxChild]->flightNum > baggage->flightNum) {
            queue->heap[i] = queue->heap[maxChild];
            i = maxChild;
        } else {
            break;
        }
    }
    queue->heap[i] = queue->heap[queue->size];
    return baggage;
}

int main()
{
    srand(time(NULL));
    Queue* bagsQueue = init_queue();
    int flights[MAX_FLIGHTS] = { 0 };
    int totalBags = 0;
    int totalWeight = 0;
    int baggageLeft = 0;

    for (int i = 0; i < MAX_BAGGAGE; i++) {
        Baggage* baggage = malloc(sizeof(Baggage));
        baggage->weight = random_int(1, MAX_WEIGHT);
        baggage->flightNum = random_int(1, MAX_FLIGHTS);
        enqueue(bagsQueue, baggage);
        totalBags++;
        totalWeight += baggage->weight;
        flights[baggage->flightNum - 1]++;
    }

    printf("Total number of bags: %d\n", totalBags);
    printf("Total weight of bags: %d kg\n", totalWeight);

    while (bagsQueue->size > 0) {
        Baggage* baggage = dequeue(bagsQueue);
        if (flights[baggage->flightNum - 1] > 0) {
            flights[baggage->flightNum - 1]--;
        } else {
            printf("Baggage with weight %d kg and flight number %d is left behind!\n", baggage->weight, baggage->flightNum);
            baggageLeft++;
        }
    }

    printf("Number of bags left behind: %d\n", baggageLeft);

    return 0;
}