//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int id;
    int cpu_burst_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int cpu_burst_time) {
    Process* process = malloc(sizeof(Process));
    process->id = id;
    process->cpu_burst_time = cpu_burst_time;
    process->waiting_time = 0;
    process->turnaround_time = 0;
    process->next = NULL;
    return process;
}

void simulateRoundRobin(Process* processes) {
    int i = 0;
    int current_processor = 0;
    time_t start_time = time(NULL);

    while (processes) {
        Process* process = processes;
        for (i = 0; i < MAX_PROCESSORS; i++) {
            if (process->id == current_processor) {
                process->waiting_time++;
                printf("Process %d is waiting on processor %d for %d clock cycles\n", process->id, current_processor, process->waiting_time);
                sleep(process->cpu_burst_time);
                process->turnaround_time = time(NULL) - start_time;
                printf("Process %d completed with turnaround time %d\n", process->id, process->turnaround_time);
                processes = processes->next;
                current_processor = (current_processor + 1) % MAX_PROCESSORS;
                break;
            }
        }
    }
}

int main() {
    Process* processes = createProcess(1, 5);
    processes = createProcess(2, 3);
    processes = createProcess(3, 8);
    processes = createProcess(4, 2);

    simulateRoundRobin(processes);

    return 0;
}