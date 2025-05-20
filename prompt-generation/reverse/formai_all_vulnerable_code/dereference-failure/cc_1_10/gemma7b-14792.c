//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_Quantum 5

typedef struct Process {
    int id;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int id, int burst_time) {
    Process* newProcess = createProcess(id, burst_time);
    if (head == NULL) {
        head = newProcess;
    } else {
        newProcess->next = head;
        head = newProcess;
    }
}

void preemptiveRoundRobin(Process* head) {
    int quantum = MAX_Quantum;
    time_t start_time = time(NULL);
    Process* currentProcess = head;

    while (currentProcess && time(NULL) - start_time < quantum) {
        printf("Process %d is running...\n", currentProcess->id);
        currentProcess->remaining_time--;
        sleep(1);

        if (currentProcess->remaining_time == 0) {
            printf("Process %d is completed.\n", currentProcess->id);
            free(currentProcess);
            currentProcess = head;
        } else {
            currentProcess = currentProcess->next;
        }
    }

    printf("All processes are completed.\n");
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 5);
    addProcess(head, 2, 3);
    addProcess(head, 3, 4);
    addProcess(head, 4, 2);

    preemptiveRoundRobin(head);

    return 0;
}