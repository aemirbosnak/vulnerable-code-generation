//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* create_process(int id, int arrival_time, int service_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    process->arrival_time = arrival_time;
    process->service_time = service_time;
    process->remaining_time = service_time;
    process->next = NULL;
    return process;
}

void add_process(Process* head, int id, int arrival_time, int service_time) {
    Process* process = create_process(id, arrival_time, service_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void round_robin(Process* head) {
    time_t start_time = time(NULL);
    Process* current_process = head;
    while (current_process) {
        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        current_process->remaining_time -= time_spent;
        if (current_process->remaining_time <= 0) {
            printf("Process %d completed.\n", current_process->process_id);
            free(current_process);
            current_process = head;
        } else {
            start_time = end_time;
            current_process = current_process->next;
        }
    }
}

int main() {
    Process* head = NULL;
    add_process(head, 1, 0, 5);
    add_process(head, 2, 2, 4);
    add_process(head, 3, 4, 3);
    add_process(head, 4, 6, 2);
    add_process(head, 5, 8, 1);

    round_robin(head);

    return 0;
}