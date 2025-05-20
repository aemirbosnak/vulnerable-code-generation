//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

void roundrobin(Process* head) {
    Process* current_process = head;
    int time_quantum = 5;

    while (current_process) {
        if (current_process->remaining_time > 0) {
            printf("Process %d is running...\n", current_process->process_id);
            current_process->remaining_time -= time_quantum;

            if (current_process->remaining_time == 0) {
                printf("Process %d has completed.\n", current_process->process_id);
            }
        } else {
            current_process = current_process->next;
        }

        time_quantum--;
        if (time_quantum == 0) {
            time_quantum = 5;
        }
    }
}

int main() {
    Process* head = NULL;
    Process* tail = NULL;

    // Create a few processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        Process* new_process = malloc(sizeof(Process));
        new_process->process_id = i + 1;
        new_process->arrival_time = rand() % 10;
        new_process->burst_time = rand() % 5;
        new_process->remaining_time = new_process->burst_time;

        if (head == NULL) {
            head = new_process;
            tail = new_process;
        } else {
            tail->next = new_process;
            tail = new_process;
        }
    }

    // Round robin scheduling algorithm
    roundrobin(head);

    return 0;
}