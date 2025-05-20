//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int process_id;
    char name[20];
    int cpu_time;
    int waiting_time;
    struct Process* next;
} Process;

Process* create_process(int id, char* name, int cpu_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    strcpy(process->name, name);
    process->cpu_time = cpu_time;
    process->waiting_time = 0;
    process->next = NULL;
    return process;
}

void add_process(Process* head, int id, char* name, int cpu_time) {
    Process* new_process = create_process(id, name, cpu_time);
    if (head == NULL) {
        head = new_process;
    } else {
        new_process->next = head;
        head = new_process;
    }
}

void round_robin(Process* head) {
    Process* current_process = head;
    while (current_process) {
        printf("Process %d: %s, CPU time: %d, Waiting time: %d\n", current_process->process_id, current_process->name, current_process->cpu_time, current_process->waiting_time);
        current_process->waiting_time++;
        sleep(1);
        current_process = current_process->next;
    }
}

int main() {
    Process* head = NULL;
    add_process(head, 1, "Process A", 5);
    add_process(head, 2, "Process B", 3);
    add_process(head, 3, "Process C", 2);
    add_process(head, 4, "Process D", 4);

    round_robin(head);

    return 0;
}