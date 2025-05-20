//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
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

void printQueue(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void cpuScheduling(Node* readyQueue, Node* blockedQueue) {
    if (readyQueue->next == NULL) {
        return;
    }

    int quantum = 5;
    Node* currentProcess = readyQueue->next;

    for (int i = 0; i < quantum; i++) {
        printf("Process %d is running...\n", currentProcess->data);
        insertAtTail(blockedQueue, currentProcess);
        free(currentProcess);
        currentProcess = readyQueue->next;
    }

    printf("All processes are blocked.\n");
    printQueue(blockedQueue);
}

int main() {
    Node* readyQueue = NULL;
    Node* blockedQueue = NULL;

    insertAtTail(readyQueue, 1);
    insertAtTail(readyQueue, 2);
    insertAtTail(readyQueue, 3);
    insertAtTail(readyQueue, 4);

    cpuScheduling(readyQueue, blockedQueue);

    return 0;
}