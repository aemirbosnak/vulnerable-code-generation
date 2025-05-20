//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

typedef struct process {
    int pid;
    char name[20];
    int cpu_burst;
    int waiting_time;
    struct process* next;
} process;

process* create_process(int pid, char* name, int cpu_burst) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->pid = pid;
    strcpy(new_process->name, name);
    new_process->cpu_burst = cpu_burst;
    new_process->waiting_time = 0;
    new_process->next = NULL;
    return new_process;
}

void add_process(process* head, process* new_process) {
    if (head == NULL) {
        head = new_process;
    } else {
        head->next = new_process;
        head = new_process;
    }
}

void round_robin(process* head) {
    process* current_process = head;
    int time_quantum = 5;

    while (current_process) {
        printf("Process %d is running...\n", current_process->pid);
        current_process->waiting_time++;
        sleep(time_quantum);
        current_process = current_process->next;
    }

    printf("All processes have completed execution.\n");
}

int main() {
    process* head = NULL;

    add_process(head, create_process(1, "Process A", 8));
    add_process(head, create_process(2, "Process B", 10));
    add_process(head, create_process(3, "Process C", 6));
    add_process(head, create_process(4, "Process D", 7));

    round_robin(head);

    return 0;
}