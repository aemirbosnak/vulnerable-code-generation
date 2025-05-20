//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100
#define MAX_BAGGAGE_SIZE 50

typedef struct {
    char name[MAX_BAGGAGE_SIZE];
    int weight;
} Baggage;

typedef struct Node {
    Baggage data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool isEmptyQueue(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, Baggage b) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = b;
    newNode->next = NULL;

    if (isEmptyQueue(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

Baggage dequeue(Queue* q) {
    Node* temp = q->front;
    Baggage b = temp->data;

    if (isEmptyQueue(q)) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }

    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return b;
}

void printQueue(Queue* q) {
    Node* current = q->front;

    while (current != NULL) {
        printf("Baggage: %s, Weight: %d\n", current->data.name, current->data.weight);
        current = current->next;
    }
}

void processBaggage(Queue* arrivals, Queue* departures) {
    while (!isEmptyQueue(arrivals)) {
        Baggage b = dequeue(arrivals);
        printf("Processing baggage: %s, Weight: %d\n", b.name, b.weight);

        int timeTaken = rand() % 10 + 1;

        printf("Baggage processing took %d seconds\n", timeTaken);

        enqueue(departures, b);
    }
}

int main() {
    srand(time(NULL));

    Queue arrivals = { .size = 0 };
    Queue departures = { .size = 0 };

    initQueue(&arrivals);
    initQueue(&departures);

    // Arrivals
    enqueue(&arrivals, (Baggage) {"Smith, John", 20});
    enqueue(&arrivals, (Baggage) {"Doe, Jane", 15});
    enqueue(&arrivals, (Baggage) {"Brown, Mike", 30});

    printf("Arrivals:\n");
    printQueue(&arrivals);

    processBaggage(&arrivals, &departures);

    printf("Departures:\n");
    printQueue(&departures);

    return 0;
}