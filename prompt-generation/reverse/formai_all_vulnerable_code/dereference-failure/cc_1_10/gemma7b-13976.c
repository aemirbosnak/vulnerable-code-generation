//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUMBER 5

typedef struct Process {
    int process_number;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

void create_process(Process** head) {
    *head = (Process*)malloc(sizeof(Process));
    (*head)->process_number = 1;
    (*head)->arrival_time = rand() % 10;
    (*head)->service_time = rand() % 5;
    (*head)->completion_time = 0;
    (*head)->next = NULL;
}

void add_process(Process** head, Process* new_process) {
    new_process->next = NULL;
    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
        *head = new_process;
    }
}

void simulate_cpu(Process* process_head) {
    Process* current_process = process_head;
    while (current_process) {
        current_process->completion_time = current_process->arrival_time + current_process->service_time;
        current_process = current_process->next;
    }
}

int main() {
    Process* process_head = NULL;
    for (int i = 0; i < MAX_PROCESS_NUMBER; i++) {
        create_process(&process_head);
    }

    simulate_cpu(process_head);

    for (Process* current_process = process_head; current_process; current_process = current_process->next) {
        printf("Process number: %d, Arrival time: %d, Service time: %d, Completion time: %d\n", current_process->process_number, current_process->arrival_time, current_process->service_time, current_process->completion_time);
    }

    return 0;
}