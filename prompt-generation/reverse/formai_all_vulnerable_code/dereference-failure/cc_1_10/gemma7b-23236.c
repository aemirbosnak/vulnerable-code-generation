//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    char name[20];
    int priority;
    int cpu_time;
    int waiting_time;
    struct Process* next;
} Process;

Process* create_process(char* name, int priority, int cpu_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    strcpy(new_process->name, name);
    new_process->priority = priority;
    new_process->cpu_time = cpu_time;
    new_process->waiting_time = 0;
    new_process->next = NULL;
    return new_process;
}

void add_process(Process* head, char* name, int priority, int cpu_time) {
    Process* new_process = create_process(name, priority, cpu_time);
    if (head == NULL) {
        head = new_process;
    } else {
        new_process->next = head;
        head = new_process;
    }
}

void round_robin(Process* head) {
    int time_quantum = 5;
    Process* current_process = head;
    while (current_process) {
        int remaining_time = current_process->cpu_time - current_process->waiting_time;
        if (remaining_time > time_quantum) {
            current_process->waiting_time += time_quantum;
            current_process = current_process->next;
        } else {
            current_process->waiting_time += remaining_time;
            current_process = current_process->next;
        }
    }
}

int main() {
    Process* head = NULL;
    add_process(head, "Process A", 1, 10);
    add_process(head, "Process B", 2, 5);
    add_process(head, "Process C", 3, 15);
    add_process(head, "Process D", 4, 8);

    round_robin(head);

    printf("Process completion times:");
    for (Process* process = head; process; process = process->next) {
        printf(" %s: %d", process->name, process->waiting_time);
    }

    return 0;
}