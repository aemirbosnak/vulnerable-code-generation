//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUM 5
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct Process* next;
} Process;

void initialize_process(Process** head) {
    *head = NULL;
}

void add_process(Process** head, int process_id, int arrival_time, int service_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->remaining_time = service_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void simulate_cpu(Process** head) {
    time_t start_time = time(NULL);
    Process* current_process = *head;

    while (!current_process->remaining_time) {
        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        printf("Process %d spent %d seconds waiting.\n", current_process->process_id, time_spent);

        current_process->remaining_time--;
        start_time = time(NULL);
    }

    printf("All processes completed.\n");
}

int main() {
    Process* head = NULL;

    // Add processes
    add_process(&head, 1, 0, 5);
    add_process(&head, 2, 2, 4);
    add_process(&head, 3, 3, 3);
    add_process(&head, 4, 4, 2);
    add_process(&head, 5, 5, 1);

    // Simulate CPU
    simulate_cpu(&head);

    return 0;
}