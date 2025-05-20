//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE 5

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process *next;
} Process;

void insert_process(Process **head, int pid, char *name, int burst_time) {
    Process *new_process = (Process *)malloc(sizeof(Process));
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

void round_robin(Process **head) {
    time_t start_time = time(NULL);
    Process *current_process = head;
    while (current_process) {
        current_process->remaining_time--;
        if (current_process->remaining_time == 0) {
            printf("Process %d (%s) completed.\n", current_process->pid, current_process->name);
            free(current_process);
            current_process = NULL;
        } else {
            current_process = current_process->next;
        }
    }

    time_t end_time = time(NULL);
    printf("Total time elapsed: %ld seconds\n", end_time - start_time);
}

int main() {
    Process *head = NULL;
    insert_process(&head, 1, "A", 5);
    insert_process(&head, 2, "B", 3);
    insert_process(&head, 3, "C", 4);
    insert_process(&head, 4, "D", 2);
    insert_process(&head, 5, "E", 6);

    round_robin(&head);

    return 0;
}