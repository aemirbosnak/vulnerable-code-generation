//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_INSTRUCTIONS 10

typedef struct Process {
    int process_id;
    int instructions_completed;
    int instructions_remaining;
    struct Process* next;
} Process;

Process* createProcess(int process_id, int instructions_remaining) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = process_id;
    process->instructions_completed = 0;
    process->instructions_remaining = instructions_remaining;
    process->next = NULL;
    return process;
}

void scheduleProcess(Process* process) {
    process->instructions_completed++;
    if (process->instructions_completed == process->instructions_remaining) {
        printf("Process %d completed.\n", process->process_id);
        free(process);
    } else {
        printf("Process %d is executing.\n", process->process_id);
    }
}

int main() {
    Process* head = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        Process* process = createProcess(i + 1, MAX_INSTRUCTIONS - i);
        if (head == NULL) {
            head = process;
        } else {
            process->next = head;
            head = process;
        }
    }

    while (!head->next) {
        scheduleProcess(head);
    }

    return 0;
}