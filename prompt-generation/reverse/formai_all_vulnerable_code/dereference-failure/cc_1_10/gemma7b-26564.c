//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct process {
    int process_id;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(int id, int arrival_time, int service_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->process_id = id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->remaining_time = service_time;
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

void preemptive_round_robin(process* head) {
    time_t current_time = time(NULL);
    process* current_process = head;
    while (current_process) {
        if (current_process->arrival_time <= current_time && current_process->remaining_time > 0) {
            current_process->remaining_time--;
            printf("Process %d is being serviced...\n", current_process->process_id);
        }
        current_process = current_process->next;
    }
}

int main() {
    process* head = NULL;
    add_process(head, create_process(1, 0, 5));
    add_process(head, create_process(2, 2, 4));
    add_process(head, create_process(3, 3, 3));
    add_process(head, create_process(4, 4, 2));
    add_process(head, create_process(5, 5, 1));

    preemptive_round_robin(head);

    return 0;
}