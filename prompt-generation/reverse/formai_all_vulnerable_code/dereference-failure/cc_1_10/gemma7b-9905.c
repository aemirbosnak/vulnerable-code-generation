//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_PROCESS 20

typedef struct Process {
    int id;
    int arrivalTime;
    int serviceTime;
    struct Process* next;
} Process;

void simulate_cpu(Process* head) {
    int i, current_time = 0, completed = 0;
    Process* current_process = NULL;

    while (!completed) {
        for (i = 0; i < MAX_PROCESSORS; i++) {
            if (current_process == NULL && head) {
                if (head->arrivalTime <= current_time) {
                    current_process = head;
                    head = head->next;
                }
            }

            if (current_process) {
                current_process->serviceTime--;
                if (current_process->serviceTime == 0) {
                    completed++;
                    printf("Process %d completed at time %d\n", current_process->id, current_time);
                    current_process = NULL;
                } else {
                    current_time++;
                }
            }
        }
    }
}

int main() {
    Process* head = NULL;
    int i, process_id = 0, arrival_time, service_time;

    // Create a linked list of processes
    for (i = 0; i < MAX_PROCESS; i++) {
        Process* newProcess = malloc(sizeof(Process));
        newProcess->id = process_id++;
        newProcess->arrivalTime = rand() % 10;
        newProcess->serviceTime = rand() % 5;
        newProcess->next = head;
        head = newProcess;
    }

    // Simulate the CPU
    simulate_cpu(head);

    return 0;
}