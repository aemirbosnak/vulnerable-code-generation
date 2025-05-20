//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int id;
    char name[20];
    int cpu_time;
    int waiting_time;
    struct Process* next;
} Process;

Process* createProcess(int id, char* name, int cpu_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    strcpy(process->name, name);
    process->cpu_time = cpu_time;
    process->waiting_time = 0;
    process->next = NULL;
    return process;
}

void scheduleProcesses(Process* head) {
    int i = 0;
    Process* current = head;
    time_t start_time = time(NULL);
    while (current) {
        current->waiting_time++;
        if (current->waiting_time == current->cpu_time) {
            printf("Process %d (%s) started at time %ld\n", current->id, current->name, start_time);
            current->waiting_time = 0;
            i++;
            if (i == MAX_PROCESSES - 1) {
                start_time = time(NULL);
            }
        }
        current = current->next;
    }
}

int main() {
    Process* head = createProcess(1, "Process A", 5);
    head = createProcess(2, "Process B", 3);
    head = createProcess(3, "Process C", 2);
    head = createProcess(4, "Process D", 4);

    scheduleProcesses(head);

    return 0;
}