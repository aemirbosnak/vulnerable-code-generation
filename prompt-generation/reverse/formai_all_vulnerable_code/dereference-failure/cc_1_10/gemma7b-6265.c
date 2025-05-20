//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10
#define MAX_CPU_TIME 10

typedef struct Process {
    int process_id;
    int cpu_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    process->cpu_time = time;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int id, int time) {
    Process* newProcess = createProcess(id, time);
    if (head == NULL) {
        head = newProcess;
    } else {
        Process* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newProcess;
    }
}

void scheduleProcess(Process* head) {
    Process* current = head;
    while (current) {
        printf("Process ID: %d, CPU Time: %d\n", current->process_id, current->cpu_time);
        current->cpu_time--;
        if (current->cpu_time == 0) {
            printf("Process %d completed.\n", current->process_id);
            free(current);
            current = head;
        } else {
            current = current->next;
        }
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 5);
    addProcess(head, 2, 3);
    addProcess(head, 3, 4);
    addProcess(head, 4, 2);
    addProcess(head, 5, 6);

    scheduleProcess(head);

    return 0;
}