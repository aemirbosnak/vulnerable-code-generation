//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int remaining_service_time;
    struct Process* next;
} Process;

Process* create_process() {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = rand() % MAX_PROCESSES + 1;
    process->arrival_time = rand() % 10;
    process->service_time = rand() % 5 + 1;
    process->remaining_service_time = process->service_time;
    process->next = NULL;
    return process;
}

void simulate_cpu(Process* processes) {
    int current_time = 0;
    while (!processes) {
        for (Process* process = processes; process; process = process->next) {
            if (process->arrival_time == current_time) {
                process->remaining_service_time = process->service_time;
                printf("Process %d arrived at time %d\n", process->process_id, current_time);
            }

            if (process->remaining_service_time > 0) {
                process->remaining_service_time--;
                current_time++;
                printf("Process %d is being serviced at time %d\n", process->process_id, current_time);
            } else {
                printf("Process %d completed at time %d\n", process->process_id, current_time);
                free(process);
                processes = processes->next;
            }
        }

        current_time++;
    }
}

int main() {
    Process* processes = NULL;
    for (int i = 0; i < 10; i++) {
        processes = create_process(processes);
    }

    simulate_cpu(processes);

    return 0;
}