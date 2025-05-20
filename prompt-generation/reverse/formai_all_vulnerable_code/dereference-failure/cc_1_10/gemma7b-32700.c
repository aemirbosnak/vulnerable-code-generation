//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void scheduler(Node* readyQueue, Node* waitingQueue) {
    if (readyQueue->next == NULL) {
        return;
    }

    // Select the process from the ready queue with the lowest CPU time
    Node* currentProcess = readyQueue;
    for (Node* process = readyQueue->next; process; process) {
        if (currentProcess->data > process->data) {
            currentProcess = process;
        }
    }

    // Move the process from the ready queue to the completed queue
    insertAtTail(waitingQueue, currentProcess);
    currentProcess->next = NULL;

    // Update the ready queue
    readyQueue = currentProcess->next;

    // Print the status of the scheduler
    printf("Current process: %d\n", currentProcess->data);
    printf("Waiting processes: %d\n", waitingQueue->data);
    printf("Ready processes: %d\n", readyQueue->data);
    printf("\n");
}

int main() {
    Node* readyQueue = NULL;
    Node* waitingQueue = NULL;

    // Insert processes into the waiting queue
    insertAtTail(waitingQueue, 3);
    insertAtTail(waitingQueue, 5);
    insertAtTail(waitingQueue, 8);

    // Start the scheduler
    scheduler(readyQueue, waitingQueue);

    // Repeat the scheduler until all processes are completed
    while (waitingQueue->next) {
        scheduler(readyQueue, waitingQueue);
    }

    // Print the final status of the scheduler
    printf("All processes completed.\n");

    return 0;
}