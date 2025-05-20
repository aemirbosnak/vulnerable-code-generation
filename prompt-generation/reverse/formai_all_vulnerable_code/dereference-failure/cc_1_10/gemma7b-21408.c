//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME 100

typedef struct Process {
    int id;
    int arrivalTime;
    int processingTime;
    int completionTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int processingTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->arrivalTime = arrivalTime;
    newProcess->processingTime = processingTime;
    newProcess->completionTime = 0;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(Process* head, int id, int arrivalTime, int processingTime) {
    Process* newProcess = createProcess(id, arrivalTime, processingTime);
    if (head == NULL) {
        head = newProcess;
    } else {
        newProcess->next = head;
        head = newProcess;
    }
}

void simulate(Process* head) {
    time_t currentTime = 0;
    Process* currentProcess = NULL;

    while (head) {
        if (currentProcess == NULL || currentTime >= head->arrivalTime) {
            currentProcess = head;
            head = head->next;
        }

        if (currentProcess) {
            currentTime++;
            currentProcess->completionTime = currentTime;
            printf("Process %d completed at time %d\n", currentProcess->id, currentProcess->completionTime);
            free(currentProcess);
            currentProcess = NULL;
        }
    }

    printf("All processes completed\n");
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 0, 5);
    addProcess(head, 2, 2, 4);
    addProcess(head, 3, 4, 3);
    addProcess(head, 4, 6, 2);
    addProcess(head, 5, 8, 4);

    simulate(head);

    return 0;
}