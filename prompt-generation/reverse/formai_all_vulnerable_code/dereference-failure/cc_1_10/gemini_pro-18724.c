//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int arrivalTime;
    int burstTime;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int arrivalTime, int burstTime) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->arrivalTime = arrivalTime;
    newNode->burstTime = burstTime;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node in the linked list in ascending order of arrival time
void insertNode(struct Node **head, struct Node *newNode) {
    if (*head == NULL || (*head)->arrivalTime >= newNode->arrivalTime) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL && current->next->arrivalTime < newNode->arrivalTime) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to calculate the waiting time for each process
void calculateWaitingTime(struct Node *head, int *waitingTime) {
    int currentTime = 0;
    struct Node *current = head;
    while (current != NULL) {
        waitingTime[current->arrivalTime] = currentTime - current->arrivalTime;
        currentTime += current->burstTime;
        current = current->next;
    }
}

// Function to calculate the turnaround time for each process
void calculateTurnaroundTime(struct Node *head, int *waitingTime, int *turnaroundTime) {
    struct Node *current = head;
    while (current != NULL) {
        turnaroundTime[current->arrivalTime] = waitingTime[current->arrivalTime] + current->burstTime;
        current = current->next;
    }
}

// Function to calculate the average waiting time and turnaround time
void calculateAverageTime(struct Node *head, int *waitingTime, int *turnaroundTime) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int count = 0;
    struct Node *current = head;
    while (current != NULL) {
        totalWaitingTime += waitingTime[current->arrivalTime];
        totalTurnaroundTime += turnaroundTime[current->arrivalTime];
        count++;
        current = current->next;
    }
    printf("Average waiting time: %.2f\n", (float)totalWaitingTime / count);
    printf("Average turnaround time: %.2f\n", (float)totalTurnaroundTime / count);
}

// Function to print the Gantt chart
void printGanttChart(struct Node *head) {
    int currentTime = 0;
    struct Node *current = head;
    while (current != NULL) {
        printf("[%d-%d]", currentTime, currentTime + current->burstTime);
        currentTime += current->burstTime;
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list of processes
    struct Node *head = NULL;
    insertNode(&head, createNode(0, 4));
    insertNode(&head, createNode(2, 2));
    insertNode(&head, createNode(4, 1));
    insertNode(&head, createNode(6, 5));

    // Calculate the waiting time and turnaround time for each process
    int waitingTime[10] = {0};
    int turnaroundTime[10] = {0};
    calculateWaitingTime(head, waitingTime);
    calculateTurnaroundTime(head, waitingTime, turnaroundTime);

    // Calculate the average waiting time and turnaround time
    calculateAverageTime(head, waitingTime, turnaroundTime);

    // Print the Gantt chart
    printGanttChart(head);

    return 0;
}