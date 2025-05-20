//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct Process* next;
} Process;

void insert_process(Process** head, int arrival_time, int execution_time) {
    Process* new_process = malloc(sizeof(Process));
    new_process->process_id = rand() % MAX_PROCESSES;
    new_process->arrival_time = arrival_time;
    new_process->execution_time = execution_time;
    new_process->remaining_time = execution_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void round_robin(Process** head) {
    int current_time = 0;
    Process* current_process = *head;

    while (current_process) {
        if (current_process->arrival_time <= current_time && current_process->remaining_time > 0) {
            current_process->remaining_time--;
            current_time++;
        } else {
            current_process = current_process->next;
        }
    }
}

int main() {
    Process* head = NULL;

    // Insert processes into the queue
    insert_process(&head, 0, 5);
    insert_process(&head, 2, 4);
    insert_process(&head, 4, 3);
    insert_process(&head, 6, 2);

    // Round robin scheduling
    round_robin(&head);

    // Print the remaining time for each process
    Process* current_process = head;
    while (current_process) {
        printf("Process ID: %d, Remaining Time: %d\n", current_process->process_id, current_process->remaining_time);
        current_process = current_process->next;
    }

    return 0;
}