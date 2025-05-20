//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME_Quantum 10

typedef struct process {
    int id;
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(int id, int burst_time) {
    process* p = malloc(sizeof(process));
    p->id = id;
    p->burst_time = burst_time;
    p->remaining_time = burst_time;
    p->next = NULL;
    return p;
}

void round_robin(process* ready_queue) {
    time_t start_time = time(NULL);
    int current_time = 0;
    while (!ready_queue->next || current_time < MAX_TIME_Quantum) {
        process* current_process = ready_queue;
        current_process->remaining_time--;
        current_time++;
        if (current_process->remaining_time == 0) {
            printf("Process %d completed.\n", current_process->id);
            free(current_process);
            ready_queue = ready_queue->next;
        }
    }
    time_t end_time = time(NULL);
    printf("Total time elapsed: %ld seconds.\n", end_time - start_time);
}

int main() {
    process* head = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        head = create_process(i + 1, rand() % MAX_TIME_Quantum);
        head->next = head;
    }

    round_robin(head);

    return 0;
}