//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int id;
    int arrivalTime;
    int serviceTime;
    int completionTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->serviceTime = serviceTime;
    process->completionTime = 0;
    process->next = NULL;
    return process;
}

void schedule(Process* head) {
    time_t currentTime = time(NULL);
    Process* currentProcess = head;
    while (currentProcess) {
        if (currentProcess->arrivalTime <= currentTime && currentProcess->completionTime == 0) {
            printf("Process %d is started at time %ld.\n", currentProcess->id, currentTime);
            currentProcess->completionTime = currentTime + currentProcess->serviceTime;
        }
        currentProcess = currentProcess->next;
    }
}

int main() {
    Process* processes = NULL;

    // Create a few processes
    processes = createProcess(1, 0, 5);
    processes = createProcess(2, 2, 3);
    processes = createProcess(3, 4, 2);
    processes = createProcess(4, 6, 4);

    // Schedule the processes
    schedule(processes);

    return 0;
}