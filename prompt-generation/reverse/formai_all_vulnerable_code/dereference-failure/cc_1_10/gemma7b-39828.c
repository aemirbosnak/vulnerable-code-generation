//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int executionTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = id;
    newProcess->arrival_time = arrivalTime;
    newProcess->execution_time = executionTime;
    newProcess->next = NULL;
    return newProcess;
}

void scheduleProcesses(Process* head) {
    int i = 0;
    Process* currentProcess = head;

    while (currentProcess) {
        printf("Process ID: %d, Arrival Time: %d, Execution Time: %d\n", currentProcess->process_id, currentProcess->arrival_time, currentProcess->execution_time);
        currentProcess = currentProcess->next;
    }
}

int main() {
    Process* head = NULL;

    // Create a few processes
    Process* process1 = createProcess(1, 0, 5);
    Process* process2 = createProcess(2, 2, 4);
    Process* process3 = createProcess(3, 3, 3);
    Process* process4 = createProcess(4, 4, 2);
    Process* process5 = createProcess(5, 5, 1);

    // Link the processes together
    head = process1;
    process1->next = process2;
    process2->next = process3;
    process3->next = process4;
    process4->next = process5;

    // Schedule the processes
    scheduleProcesses(head);

    return 0;
}