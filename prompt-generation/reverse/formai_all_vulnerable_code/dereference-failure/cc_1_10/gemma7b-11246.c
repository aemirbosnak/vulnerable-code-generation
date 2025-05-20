//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(int id, int arrivalTime, int executionTime) {
    Process* newNode = malloc(sizeof(Process));
    newNode->process_id = id;
    newNode->arrival_time = arrivalTime;
    newNode->execution_time = executionTime;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Process* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void simulate() {
    int time = 0;
    Process* currentProcess = head;

    while (currentProcess) {
        if (time >= currentProcess->arrival_time) {
            printf("Process %d is started at time %d\n", currentProcess->process_id, time);
            time += currentProcess->execution_time;
            printf("Process %d is completed at time %d\n", currentProcess->process_id, time);
            currentProcess = currentProcess->next;
        } else {
            printf("Waiting for process %d at time %d\n", currentProcess->process_id, time);
            time++;
        }
    }

    printf("All processes are completed.\n");
}

int main() {
    insertProcess(1, 0, 5);
    insertProcess(2, 2, 4);
    insertProcess(3, 3, 3);
    insertProcess(4, 4, 2);

    simulate();

    return 0;
}