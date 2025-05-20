//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME_Quantum 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int process_id, int arrival_time, int burst_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = process_id;
    newProcess->arrival_time = arrival_time;
    newProcess->burst_time = burst_time;
    newProcess->remaining_time = burst_time;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(Process** head, int process_id, int arrival_time, int burst_time) {
    Process* newProcess = createProcess(process_id, arrival_time, burst_time);
    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*head)->next = newProcess;
    }
}

void roundRobin(Process** head) {
    Process* currentProcess = *head;
    time_t currentTime = time(NULL);
    while (currentProcess) {
        // Calculate remaining time
        int remainingTime = currentProcess->remaining_time - (int)(time(NULL) - currentTime);

        // If remaining time is greater than 0, process is still active
        if (remainingTime > 0) {
            // Update current process remaining time
            currentProcess->remaining_time = remainingTime;

            // Sleep for the remainder of the time quantum
            sleep(MAX_TIME_Quantum - remainingTime);

            // Update the current time
            currentTime = time(NULL);
        } else {
            // Process is complete, remove from the queue
            Process* nextProcess = currentProcess->next;
            free(currentProcess);
            *head = nextProcess;
        }
    }
}

int main() {
    Process* head = NULL;

    // Add some processes
    addProcess(&head, 1, 0, 5);
    addProcess(&head, 2, 2, 3);
    addProcess(&head, 3, 4, 2);
    addProcess(&head, 4, 6, 4);

    // Round Robin scheduling
    roundRobin(&head);

    // Print completion status
    printf("Process completion status:\n");
    for (Process* process = head; process; process = process->next) {
        printf("Process ID: %d, Completion Time: %d\n", process->process_id, time(NULL) - process->arrival_time);
    }

    return 0;
}