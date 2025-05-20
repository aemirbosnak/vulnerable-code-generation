//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int id;
    int weight;
    char destination[50];
} Bag;

typedef struct Node {
    Bag data;
    struct Node* next;
} Node;

Node* createNode(Bag data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** queue, Bag data) {
    Node* newNode = createNode(data);
    if (*queue == NULL) {
        *queue = newNode;
    } else {
        Node* last = *queue;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

Bag dequeue(Node** queue) {
    Node* temp = *queue;
    Bag data = temp->data;
    *queue = temp->next;
    free(temp);
    return data;
}

void printQueue(Node* queue) {
    while (queue != NULL) {
        printf("Bag ID: %d, Weight: %d, Destination: %s\n", queue->data.id, queue->data.weight, queue->data.destination);
        queue = queue->next;
    }
}

int main() {
    Node* queue = NULL;
    int totalWeight = 0;
    int numBags = 0;

    // Check in baggage
    enqueue(&queue, (Bag){1, 10, "Paris"});
    enqueue(&queue, (Bag){2, 20, "New York"});
    enqueue(&queue, (Bag){3, 15, "London"});
    enqueue(&queue, (Bag){4, 5, "Tokyo"});
    enqueue(&queue, (Bag){5, 25, "Sydney"});

    // Print out baggage in check-in order
    printf("Baggage in check-in order:\n");
    while (queue != NULL) {
        Bag data = dequeue(&queue);
        printf("Bag ID: %d, Weight: %d, Destination: %s\n", data.id, data.weight, data.destination);
        numBags++;
    }

    // Load baggage onto plane in weight order
    printf("\nBaggage loaded onto plane in weight order:\n");
    while (queue != NULL) {
        Bag data = queue->data;
        totalWeight += data.weight;
        printf("Bag ID: %d, Weight: %d\n", data.id, data.weight);
        enqueue(&queue, dequeue(queue));
    }

    printf("\nTotal weight of baggage: %d\n", totalWeight);
    printf("Number of bags checked in: %d\n", numBags);

    return 0;
}