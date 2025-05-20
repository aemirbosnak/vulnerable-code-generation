//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LUGGAGE 1000
#define MAX_BAG_SIZE 30
#define MAX_FLIGHTS 10
#define MAX_HANDLERS 5

struct BaggageUnit{
    int weight;
    char flightNo[6];
    int luggageId;
    bool handled;
};

struct LuggageQueue{
    int front;
    int rear;
    int size;
    struct BaggageUnit *baggageArray;
};

void initQueue(struct LuggageQueue *queue){
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->baggageArray = (struct BaggageUnit*) malloc(MAX_LUGGAGE * sizeof(struct BaggageUnit));
}

bool isFull(struct LuggageQueue *queue){
    if(queue->front == 0 && queue->rear == MAX_LUGGAGE - 1) return true;
    if(queue->front == queue->rear + 1) return true;
    return false;
}

bool isEmpty(struct LuggageQueue *queue){
    if(queue->front == -1) return true;
    return false;
}

void enqueue(struct LuggageQueue *queue, struct BaggageUnit *baggage){
    if(isFull(queue)){
        printf("\nLuggage queue is full!\n");
        return;
    }
    if(queue->front == -1) queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_LUGGAGE;
    queue->baggageArray[queue->rear] = *baggage;
    queue->size++;
}

struct BaggageUnit dequeue(struct LuggageQueue *queue){
    struct BaggageUnit *baggage = (struct BaggageUnit*) malloc(sizeof(struct BaggageUnit));
    if(isEmpty(queue)){
        printf("\nLuggage queue is empty!\n");
        struct BaggageUnit nullLuggage = {0, "", -1, false};
        return nullLuggage;
    }
    *baggage = queue->baggageArray[queue->front];
    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    else queue->front = (queue->front + 1) % MAX_LUGGAGE;
    queue->size--;
    return *baggage;
}

int generateRandomWeight(){
    return (rand() % MAX_BAG_SIZE) + 1;
}

void generateRandomFlight(char *flightNo){
    int randNum = (rand() % 900) + 100;
    sprintf(flightNo, "ABC%d", randNum);
}

void generateLuggageQueue(struct LuggageQueue *queue, int numLuggage){
    for(int i=0; i<numLuggage; i++){
        struct BaggageUnit baggage;
        baggage.weight = generateRandomWeight();
        generateRandomFlight(baggage.flightNo);
        baggage.luggageId = i+1;
        baggage.handled = false;
        enqueue(queue, &baggage);
    }
}

void printLuggageQueue(struct LuggageQueue *queue){
    if(isEmpty(queue)){
        printf("\nLuggage queue is empty!\n");
        return;
    }
    printf("\nLuggage Queue:\n");
    for(int i=queue->front; i<=queue->rear; i++){
        printf("Luggage ID: %d, Weight: %d, Flight No: %s, Handled: %s\n", queue->baggageArray[i].luggageId, queue->baggageArray[i].weight, queue->baggageArray[i].flightNo, queue->baggageArray[i].handled ? "Yes" : "No");
    }
}

void simulateBaggageHandling(struct LuggageQueue *queue, int numHandlers){
    int totalTime = 0, totalWeight = 0, totalLuggage = queue->size;
    while(queue->size > 0){
        int numHandled = 0;
        for(int i=0; i<numHandlers; i++){
            if(!isEmpty(queue)){
                struct BaggageUnit baggage = dequeue(queue);
                printf("\nHandler %d handling Luggage ID: %d, Weight: %d, Flight No: %s", i+1, baggage.luggageId, baggage.weight, baggage.flightNo);
                baggage.handled = true;
                totalWeight += baggage.weight;
                numHandled++;
            }
        }
        totalTime += 10;
        printf("\n\nProcessed %d luggage in 10 seconds\n", numHandled);
        printLuggageQueue(queue);
        printf("\n");
    }
    float avgWeight = (float) totalWeight / totalLuggage;
    printf("\n\nTotal time taken to process all luggage: %d seconds\n", totalTime);
    printf("Total weight of all luggage: %d kg\n", totalWeight);
    printf("Average weight of all luggage: %.2f kg\n", avgWeight);
}

int main(){
    srand(time(0));
    int numLuggage = 15;
    struct LuggageQueue queue;
    initQueue(&queue);
    generateLuggageQueue(&queue, numLuggage);
    printf("Initial Luggage Queue:\n");
    printLuggageQueue(&queue);
    printf("\n");
    int numHandlers = 3;
    simulateBaggageHandling(&queue, numHandlers);
    return 0;
}