//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    struct Process* next;
} Process;

void initialize_queue(Process** head, int size) {
    *head = NULL;
    for (int i = 0; i < size; i++) {
        *head = malloc(sizeof(Process));
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void enqueue(Process** head, int arrival_time, int burst_time) {
    Process* new_process = malloc(sizeof(Process));
    new_process->process_id = rand() % MAX_PROCESSORS;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
        head = &((*head)->next);
    }
}

void round_robin(Process** head) {
    Process* current_process = *head;
    time_t start_time = time(NULL);
    time_t end_time;

    while (current_process) {
        end_time = time(NULL);
        if (end_time - start_time >= current_process->burst_time) {
            printf("Process %d completed.\n", current_process->process_id);
            free(current_process);
            current_process = (*head)->next;
            start_time = time(NULL);
        }
    }
}

int main() {
    Process** queue = NULL;
    initialize_queue(&queue, MAX_QUEUE_SIZE);

    // Enqueue processes
    enqueue(queue, 0, 5);
    enqueue(queue, 2, 3);
    enqueue(queue, 4, 2);
    enqueue(queue, 6, 4);

    // Round robin scheduling
    round_robin(queue);

    return 0;
}