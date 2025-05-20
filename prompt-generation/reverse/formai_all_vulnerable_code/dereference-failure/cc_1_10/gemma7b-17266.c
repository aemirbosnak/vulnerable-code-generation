//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

void insert_process(process** head, int pid, char* name, int burst_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->pid = pid;
    strcpy(new_process->name, name);
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void round_robin(process** head) {
    time_t start_time = time(NULL);
    process* current_process = *head;
    int completed = 0;

    while (!completed) {
        current_process->remaining_time--;
        if (current_process->remaining_time == 0) {
            completed = 1;
        } else {
            printf("Process %d is waiting...\n", current_process->pid);
            sleep(1);
            current_process = (*head)->next;
        }
    }

    time_t end_time = time(NULL);
    printf("Total time taken: %d seconds\n", end_time - start_time);
}

int main() {
    process* head = NULL;
    insert_process(&head, 1, "Process A", 5);
    insert_process(&head, 2, "Process B", 3);
    insert_process(&head, 3, "Process C", 4);
    insert_process(&head, 4, "Process D", 2);
    insert_process(&head, 5, "Process E", 6);

    round_robin(&head);

    return 0;
}