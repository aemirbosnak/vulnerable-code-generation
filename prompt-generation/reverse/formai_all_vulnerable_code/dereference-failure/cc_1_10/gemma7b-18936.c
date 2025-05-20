//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5

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
    int currentTime = 0;
    Process* currentProcess = head;

    while (currentProcess) {
        if (currentProcess->arrivalTime <= currentTime) {
            currentTime += currentProcess->serviceTime;
            currentProcess->completionTime = currentTime;
            printf("Process %d completed at time %d\n", currentProcess->id, currentProcess->completionTime);
            currentProcess = currentProcess->next;
        } else {
            currentTime++;
        }
    }

    printf("All processes completed\n");
}

int main() {
    Process* head = createProcess(1, 0, 5);
    createProcess(2, 2, 3);
    createProcess(3, 4, 2);
    createProcess(4, 6, 4);
    createProcess(5, 8, 3);

    schedule(head);

    return 0;
}