//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_TIME_Quantum 3

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int process_id, int arrival_time, int execution_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = process_id;
    newProcess->arrival_time = arrival_time;
    newProcess->execution_time = execution_time;
    newProcess->remaining_time = execution_time;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(Process** head, int process_id, int arrival_time, int execution_time) {
    Process* newProcess = createProcess(process_id, arrival_time, execution_time);
    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*head)->next = newProcess;
        *head = newProcess;
    }
}

void preemptiveRoundRobin(Process** head) {
    Process* currentProcess = *head;
    int timeQuantum = MAX_TIME_Quantum;
    int completedProcesses = 0;

    while (completedProcesses < MAX_PROCESSES) {
        if (currentProcess->remaining_time > 0) {
            currentProcess->remaining_time--;
            printf("Process %d is executing... (Time remaining: %d)\n", currentProcess->process_id, currentProcess->remaining_time);
        } else {
            completedProcesses++;
            printf("Process %d is completed.\n", currentProcess->process_id);
            currentProcess = currentProcess->next;
        }

        if (timeQuantum == 0) {
            timeQuantum = MAX_TIME_Quantum;
            printf("Time quantum is over. Switching to the next process...\n");
        } else {
            timeQuantum--;
        }
    }

    printf("All processes are completed.\n");
}

int main() {
    Process* head = NULL;
    addProcess(&head, 1, 0, 5);
    addProcess(&head, 2, 2, 4);
    addProcess(&head, 3, 1, 3);
    addProcess(&head, 4, 3, 2);
    addProcess(&head, 5, 4, 6);

    preemptiveRoundRobin(&head);

    return 0;
}