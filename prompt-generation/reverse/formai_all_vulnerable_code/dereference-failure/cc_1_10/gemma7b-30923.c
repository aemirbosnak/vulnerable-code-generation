//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_queue(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void enqueue(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void schedule() {
    Node* readyQueue = NULL;
    Node* waitingQueue = NULL;

    // Simulate some tasks in the waiting queue
    enqueue(&waitingQueue, 1);
    enqueue(&waitingQueue, 3);
    enqueue(&waitingQueue, 5);

    // Simulate the CPU being busy
    printf("CPU is busy...\n");

    // Move tasks from waiting to ready queue
    while (!waitingQueue) {
        break;
    }
    enqueue(&readyQueue, waitingQueue);
    waitingQueue = waitingQueue->next;

    // Simulate the task execution
    printf("Task %d is running...\n", readyQueue->data);

    // Move completed task from ready to waiting queue
    readyQueue = readyQueue->next;
    enqueue(&waitingQueue, readyQueue);

    print_queue(waitingQueue);
    print_queue(readyQueue);
}

int main() {
    schedule();
    return 0;
}