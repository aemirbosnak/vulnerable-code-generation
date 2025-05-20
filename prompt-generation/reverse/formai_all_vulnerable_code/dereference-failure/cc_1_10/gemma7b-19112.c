//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

struct process {
    int pid;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct process* next;
};

void simulate_cpu_scheduling(struct process* head) {
    int current_time = 0;
    struct process* current_process = NULL;

    while (!head->next || current_time < head->arrival_time) {
        current_time++;
    }

    while (head) {
        if (current_process == NULL || current_time >= head->arrival_time) {
            current_process = head;
            head = head->next;
        }

        current_process->remaining_time--;

        if (current_process->remaining_time == 0) {
            printf("Process %d completed.\n", current_process->pid);
            current_process = NULL;
        }

        current_time++;
    }
}

int main() {
    struct process* head = NULL;

    // Create a few processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        struct process* new_process = (struct process*)malloc(sizeof(struct process));
        new_process->pid = i + 1;
        new_process->arrival_time = rand() % 10;
        new_process->service_time = rand() % 5;
        new_process->remaining_time = new_process->service_time;

        if (head == NULL) {
            head = new_process;
        } else {
            new_process->next = head;
            head = new_process;
        }
    }

    // Simulate CPU scheduling
    simulate_cpu_scheduling(head);

    return 0;
}