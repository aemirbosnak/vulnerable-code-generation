//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int id;
    int arrivalTime;
    int processingTime;
    struct Process* next;
} Process;

Process* head = NULL;

void addProcess(int id, int arrivalTime, int processingTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->arrivalTime = arrivalTime;
    newProcess->processingTime = processingTime;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* currentProcess = head;
        while (currentProcess->next != NULL) {
            currentProcess = currentProcess->next;
        }
        currentProcess->next = newProcess;
    }
}

void schedule() {
    time_t currentTime = time(NULL);
    Process* currentProcess = head;

    while (currentProcess && currentTime >= currentProcess->arrivalTime) {
        printf("Process %d is running\n", currentProcess->id);
        sleep(currentProcess->processingTime);
        currentProcess = currentProcess->next;
    }

    printf("All processes are finished\n");
}

int main() {
    addProcess(1, 0, 5);
    addProcess(2, 2, 4);
    addProcess(3, 3, 3);
    addProcess(4, 4, 2);
    addProcess(5, 5, 1);

    schedule();

    return 0;
}