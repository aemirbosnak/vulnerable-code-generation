//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROC 5
#define MAX_Quantum 10

typedef struct Process {
    int pid;
    char name[20];
    int cpu_burst;
    int remaining_burst;
    int quantum;
    struct Process* next;
} Process;

Process* createProcess(char* name, int cpu_burst, int quantum) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->pid = getpid();
    strcpy(newProcess->name, name);
    newProcess->cpu_burst = cpu_burst;
    newProcess->remaining_burst = cpu_burst;
    newProcess->quantum = quantum;
    newProcess->next = NULL;
    return newProcess;
}

void roundRobin(Process* head) {
    Process* currentProcess = head;
    while (currentProcess) {
        printf("Process: %s, Remaining Burst: %d\n", currentProcess->name, currentProcess->remaining_burst);
        sleep(currentProcess->quantum);
        currentProcess->remaining_burst--;
        if (currentProcess->remaining_burst == 0) {
            printf("Process: %s completed.\n", currentProcess->name);
        }
        currentProcess = currentProcess->next;
    }
}

int main() {
    Process* head = NULL;
    head = createProcess("Process A", 20, 3);
    createProcess("Process B", 10, 2);
    createProcess("Process C", 15, 4);
    createProcess("Process D", 12, 3);
    createProcess("Process E", 8, 2);

    roundRobin(head);

    return 0;
}