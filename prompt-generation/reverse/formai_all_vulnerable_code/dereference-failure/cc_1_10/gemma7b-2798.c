//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void scheduling(Node* readyQueue, Node* blockedQueue) {
    // Round robin scheduling
    Node* current = readyQueue;
    time_t start = time(NULL);
    while (current) {
        // Simulate some execution time
        time_t end = time(NULL);
        printf("Executing process %d for %d seconds...\n", current->data, end - start);

        // Move process to blocked queue
        insert(blockedQueue, current);
        current = current->next;
    }

    // Print blocked queue
    printList(blockedQueue);
}

int main() {
    // Create a linked list for the ready queue and blocked queue
    Node* readyQueue = NULL;
    Node* blockedQueue = NULL;

    // Insert processes into the ready queue
    insert(readyQueue, 1);
    insert(readyQueue, 3);
    insert(readyQueue, 5);

    // Schedule the processes
    scheduling(readyQueue, blockedQueue);

    // Print the blocked queue
    printList(blockedQueue);

    return 0;
}