//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 20

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = process_id;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->next = NULL;
    return process;
}

void add_process(Process** head, int process_id, int arrival_time, int burst_time) {
    Process* process = create_process(process_id, arrival_time, burst_time);
    if (*head == NULL) {
        *head = process;
    } else {
        (*head)->next = process;
        *head = process;
    }
}

void schedule(Process** head) {
    time_t current_time = time(NULL);
    Process* process = *head;
    while (process) {
        if (process->arrival_time <= current_time && process->remaining_time > 0) {
            printf("Process %d is being scheduled\n", process->process_id);
            process->remaining_time--;
        }
        process = process->next;
    }
}

int main() {
    Process** head = NULL;
    add_process(&head, 1, 0, 5);
    add_process(&head, 2, 2, 4);
    add_process(&head, 3, 3, 3);
    add_process(&head, 4, 4, 2);
    schedule(&head);
    return 0;
}