//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESS 5

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(int pid, char* name, int burst_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->pid = pid;
    strcpy(newProcess->name, name);
    newProcess->burst_time = burst_time;
    newProcess->remaining_time = burst_time;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* lastProcess = head;
        while (lastProcess->next) {
            lastProcess = lastProcess->next;
        }
        lastProcess->next = newProcess;
    }
}

void scheduleProcess() {
    Process* currentProcess = head;

    if (currentProcess == NULL) {
        return;
    }

    int totalTime = 0;
    while (currentProcess) {
        printf("Process: %s, remaining time: %d\n", currentProcess->name, currentProcess->remaining_time);
        sleep(1);
        currentProcess->remaining_time--;
        totalTime++;
    }

    printf("Total time: %d\n", totalTime);
}

int main() {
    insertProcess(1, "Process A", 5);
    insertProcess(2, "Process B", 3);
    insertProcess(3, "Process C", 4);
    insertProcess(4, "Process D", 2);
    insertProcess(5, "Process E", 3);

    scheduleProcess();

    return 0;
}