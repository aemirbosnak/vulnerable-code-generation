//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME_Quantum 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int execution_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = process_id;
    process->arrival_time = arrival_time;
    process->execution_time = execution_time;
    process->remaining_time = execution_time;
    process->next = NULL;
    return process;
}

void add_process(Process* head, int process_id, int arrival_time, int execution_time) {
    Process* new_process = create_process(process_id, arrival_time, execution_time);
    if (head == NULL) {
        head = new_process;
    } else {
        new_process->next = head;
        head = new_process;
    }
}

void round_robin(Process* head) {
    time_t start_time = time(NULL);
    int current_time = 0;
    Process* current_process = head;

    while (current_process) {
        if (current_time >= current_process->arrival_time) {
            current_process->remaining_time--;
            if (current_process->remaining_time == 0) {
                printf("Process %d completed.\n", current_process->process_id);
            }
        }

        current_time++;

        if (time(NULL) - start_time >= MAX_TIME_Quantum) {
            start_time = time(NULL);
            current_time = 0;
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