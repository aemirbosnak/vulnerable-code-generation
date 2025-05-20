//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NR_PROC 5
#define ROUND_robin_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int pid, char* name, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->pid = pid;
    strcpy(process->name, name);
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->next = NULL;
    return process;
}

void roundRobin(Process* processes) {
    int current_process = 0;
    while (!processes->next) {
        processes->remaining_time--;
        if (processes->remaining_time == 0) {
            printf("Process %s completed.\n", processes->name);
            processes = processes->next;
            current_process = 0;
        } else {
            current_process++;
            if (current_process == ROUND_robin_SIZE - 1) {
                current_process = 0;
            }
            processes = processes->next;
        }
    }
    printf("All processes completed.\n");
}

int main() {
    Process* processes = NULL;
    processes = createProcess(1, "A", 5);
    processes = createProcess(2, "B", 3);
    processes = createProcess(3, "C", 2);
    processes = createProcess(4, "D", 4);
    processes = createProcess(5, "E", 3);

    roundRobin(processes);

    return 0;
}