//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 3
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int process_id;
    char *process_name;
    int cpu_time;
    int waiting_time;
    struct Process *next;
} Process;

Process *head = NULL;

void insert_process(int process_id, char *process_name, int cpu_time) {
    Process *new_process = (Process *)malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->process_name = process_name;
    new_process->cpu_time = cpu_time;
    new_process->waiting_time = 0;
    new_process->next = NULL;

    if (head == NULL) {
        head = new_process;
    } else {
        Process *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_process;
    }
}

void schedule() {
    srand(time(NULL));
    int quantum = rand() % MAX_SCHEDULE_SIZE;

    Process *current_process = head;
    while (current_process) {
        current_process->waiting_time++;

        if (current_process->waiting_time >= quantum) {
            printf("Process %d is running...\n", current_process->process_id);
            current_process->waiting_time = 0;
        }
        current_process = current_process->next;
    }
}

int main() {
    insert_process(1, "Process A", 5);
    insert_process(2, "Process B", 3);
    insert_process(3, "Process C", 7);

    schedule();

    return 0;
}