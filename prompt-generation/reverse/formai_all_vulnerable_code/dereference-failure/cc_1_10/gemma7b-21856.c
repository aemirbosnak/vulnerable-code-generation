//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

struct process {
    int id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct process* next;
};

void schedule_process(struct process* head) {
    struct process* current = head;
    struct process* next = NULL;
    time_t start_time = time(NULL);

    while (current) {
        next = current->next;
        current->completion_time = start_time + current->service_time;

        if (next) {
            if (current->arrival_time <= next->arrival_time) {
                current = next;
            } else {
                current = current->next;
            }
        } else {
            current->completion_time = start_time + current->service_time;
            break;
        }
    }

    head = current;
}

int main() {
    struct process* head = NULL;

    // Create some processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        struct process* new_process = malloc(sizeof(struct process));
        new_process->id = i;
        new_process->arrival_time = rand() % 10;
        new_process->service_time = rand() % 5;

        if (head) {
            new_process->next = head;
        }

        head = new_process;
    }

    // Schedule the processes
    schedule_process(head);

    // Print the completion times
    for (struct process* current = head; current; current = current->next) {
        printf("Process %d completion time: %d\n", current->id, current->completion_time);
    }

    return 0;
}