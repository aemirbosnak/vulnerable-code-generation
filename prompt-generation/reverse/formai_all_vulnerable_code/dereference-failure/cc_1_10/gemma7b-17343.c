//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_INSTRUCTIONS 10

typedef struct Process {
    int id;
    int instructions;
    int waiting_time;
    int burst_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int instructions) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->instructions = instructions;
    process->waiting_time = 0;
    process->burst_time = rand() % MAX_INSTRUCTIONS;
    process->next = NULL;
    return process;
}

void scheduleProcess(Process* process) {
    process->waiting_time++;
    printf("Process %d waiting for %d instructions\n", process->id, process->waiting_time);
}

void simulate() {
    Process* head = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        head = createProcess(i + 1, rand() % MAX_INSTRUCTIONS);
        scheduleProcess(head);
    }

    time_t start = time(NULL);
    for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
        for (Process* process = head; process; process = process->next) {
            if (process->burst_time > 0) {
                process->burst_time--;
                printf("Process %d executing for %d instructions\n", process->id, process->burst_time);
            } else {
                scheduleProcess(process);
            }
        }
        time_t end = time(NULL);
        printf("Time elapsed: %ld seconds\n", end - start);
    }
}

int main() {
    simulate();
    return 0;
}