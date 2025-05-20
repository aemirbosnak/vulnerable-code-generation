//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSORS 4
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

void insert_process(Process** head, int arrival_time, int burst_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = rand() % NUM_PROCESSORS;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void simulate_scheduler(Process** head) {
    time_t start_time = time(NULL);

    while (!head) {
        // Wait for the next process to arrive
        sleep(1);
    }

    Process* current_process = head;
    while (current_process) {
        // Calculate the remaining time for the process
        current_process->remaining_time--;

        // If the remaining time is 0, the process is complete
        if (current_process->remaining_time == 0) {
            printf("Process %d is completed.\n", current_process->process_id);
            free(current_process);
            current_process = NULL;
        } else {
            // Move to the next process in the queue
            current_process = current_process->next;
        }
    }

    time_t end_time = time(NULL);
    printf("Total time elapsed: %ld seconds\n", end_time - start_time);
}

int main() {
    Process* head = NULL;

    // Insert some processes into the queue
    insert_process(&head, 0, 5);
    insert_process(&head, 2, 3);
    insert_process(&head, 3, 6);
    insert_process(&head, 4, 4);

    // Simulate the scheduler
    simulate_scheduler(&head);

    return 0;
}