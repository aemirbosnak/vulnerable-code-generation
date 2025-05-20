//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

typedef struct Process {
    int process_id;
    int cpu_time_remaining;
    struct Process* next;
} Process;

Process* head = NULL;

void add_process(int process_id, int cpu_time_remaining) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->cpu_time_remaining = cpu_time_remaining;
    new_process->next = NULL;

    if (head == NULL) {
        head = new_process;
    } else {
        head->next = new_process;
        head = new_process;
    }
}

void schedule_processes() {
    Process* current_process = head;

    while (current_process) {
        current_process->cpu_time_remaining--;

        if (current_process->cpu_time_remaining == 0) {
            printf("Process %d completed.\n", current_process->process_id);
            free(current_process);
            current_process = head;
        } else {
            current_process = current_process->next;
        }
    }
}

int main() {
    add_process(1, 10);
    add_process(2, 8);
    add_process(3, 6);
    add_process(4, 4);

    schedule_processes();

    return 0;
}