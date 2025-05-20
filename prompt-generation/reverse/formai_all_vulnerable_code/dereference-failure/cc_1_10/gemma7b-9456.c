//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUEUE_SIZE 5

typedef struct process {
    int process_id;
    char name[20];
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct process* next;
} process;

void insert_process(process** head, process* new_process) {
    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
        *head = new_process;
    }
}

void round_robin(process** head) {
    int i = 0;
    process* current_process = *head;
    while (current_process) {
        current_process->remaining_time--;
        if (current_process->remaining_time == 0) {
            printf("Process %d completed.\n", current_process->process_id);
            insert_process(head, current_process);
            current_process = NULL;
        } else {
            i++;
            if (i == MAX_QUEUE_SIZE) {
                current_process = NULL;
            } else {
                current_process = current_process->next;
            }
        }
    }
}

int main() {
    process* head = NULL;
    process* new_process;

    // Create some processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        new_process = (process*)malloc(sizeof(process));
        new_process->process_id = i + 1;
        new_process->arrival_time = rand() % MAX_QUEUE_SIZE;
        new_process->execution_time = rand() % MAX_QUEUE_SIZE;
        new_process->remaining_time = new_process->execution_time;
        insert_process(&head, new_process);
    }

    // Round robin scheduling
    round_robin(&head);

    return 0;
}