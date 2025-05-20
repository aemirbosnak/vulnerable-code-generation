//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Global Variables
int baggageCount = 0;
int currentCapacity = 0;
int maxCapacity = 50;

// Node Definition
typedef struct node {
    int baggageWeight;
    struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

// Function to add baggage to queue
void enqueue(int weight) {
    if(currentCapacity + weight <= maxCapacity) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->baggageWeight = weight;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        baggageCount++;
        currentCapacity += weight;
        printf("Added Baggage with weight %dkg to the queue\n", weight);
    } else {
        printf("Sorry, we cannot accept this luggage as it will exceed the weight limit\n");
    }
}

// Function to remove baggage from queue
void dequeue() {
    if(head == NULL) {
        printf("Queue is empty, no baggage to remove\n");
    } else {
        Node *temp = head;
        head = head->next;
        currentCapacity -= temp->baggageWeight;
        printf("Removed Baggage with weight %dkg from the queue\n", temp->baggageWeight);
        free(temp);
        baggageCount--;
    }
}

// Function to display the current queue status
void displayQueue() {
    if(head == NULL) {
        printf("Queue is empty\n");
    } else {
        Node *current = head;
        printf("Current Queue Status:\n");
        while(current != NULL) {
            printf("Baggage %d: %dkg\n",current->baggageWeight);
            current = current->next;
        }
        printf("Total Number of Baggage: %d\n", baggageCount);
        printf("Remaining Capacity: %dkg\n", maxCapacity - currentCapacity);
    }
}
 
int main() {

    // Simulate Baggage Handling
    enqueue(25);
    enqueue(15);
    enqueue(20);
    displayQueue();
    dequeue();
    displayQueue();
    enqueue(10);
    enqueue(35);
    displayQueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    displayQueue();

    return 0;
}