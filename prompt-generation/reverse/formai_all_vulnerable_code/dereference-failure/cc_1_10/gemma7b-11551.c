//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

void create_process(Process** head, int process_id, int arrival_time, int service_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->completion_time = -1;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void round_robin(Process* head) {
    int current_time = 0;
    Process* current_process = head;

    while (!current_process->completion_time) {
        current_process->completion_time = current_time + current_process->service_time;
        current_process = current_process->next;
        current_time++;
    }
}

int main() {
    Process* head = NULL;

    // Create some processes
    create_process(&head, 1, 0, 5);
    create_process(&head, 2, 2, 4);
    create_process(&head, 3, 4, 3);
    create_process(&head, 4, 6, 2);

    // Round robin scheduling
    round_robin(head);

    // Print completion times
    Process* process = head;
    while (process) {
        printf("Process ID: %d, Completion Time: %d\n", process->process_id, process->completion_time);
        process = process->next;
    }

    return 0;
}