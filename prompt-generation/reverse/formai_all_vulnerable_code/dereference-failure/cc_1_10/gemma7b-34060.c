//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int id;
    int arrival_time;
    int service_time;
    int waiting_time;
    struct Process* next;
} Process;

void initialize_queue(Process** head) {
    *head = NULL;
}

void enqueue(Process** head, Process* process) {
    if (*head == NULL) {
        *head = process;
    } else {
        (*head)->next = process;
        *head = process;
    }
}

void dequeue(Process** head) {
    Process* process = *head;
    *head = process->next;
    free(process);
}

void simulate_cpu(Process** head) {
    time_t start_time = time(NULL);
    Process* current_process = *head;
    while (*head) {
        time_t end_time = time(NULL);
        int waiting_time = end_time - start_time - current_process->arrival_time;
        current_process->waiting_time = waiting_time;
        printf("Process %d waiting time is %d\n", current_process->id, current_process->waiting_time);
        dequeue(head);
        current_process = *head;
        start_time = end_time;
    }
}

int main() {
    Process* processes[MAX_PROCESS];
    initialize_queue(&processes);

    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i] = (Process*)malloc(sizeof(Process));
        processes[i]->id = i + 1;
        processes[i]->arrival_time = rand() % MAX_QUEUE_SIZE;
        processes[i]->service_time = rand() % MAX_QUEUE_SIZE;
        enqueue(&processes, processes[i]);
    }

    simulate_cpu(&processes);

    return 0;
}