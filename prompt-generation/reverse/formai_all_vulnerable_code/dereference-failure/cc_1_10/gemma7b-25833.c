//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROC 5

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

void create_process(Process** head) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->pid = rand() % MAX_PROC;
    snprintf(new_process->name, 20, "Process %d", new_process->pid);
    new_process->burst_time = rand() % 5 + 1;
    new_process->remaining_time = new_process->burst_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void round_robin(Process* head) {
    time_t start_time = time(NULL);
    Process* current_process = head;

    while (current_process) {
        printf("Process: %s, Remaining Time: %d\n", current_process->name, current_process->remaining_time);

        current_process->remaining_time--;

        if (current_process->remaining_time == 0) {
            printf("Process: %s finished.\n", current_process->name);
            free(current_process);
            current_process = NULL;
        } else {
            current_process = current_process->next;
        }

        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        printf("Time spent: %d seconds\n", time_spent);
        start_time = end_time;
    }
}

int main() {
    Process* head = NULL;

    // Create a few processes
    for (int i = 0; i < 10; i++) {
        create_process(&head);
    }

    // Round robin scheduling
    round_robin(head);

    return 0;
}