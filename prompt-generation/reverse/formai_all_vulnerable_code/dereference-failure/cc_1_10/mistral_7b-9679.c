//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

typedef struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    struct Process *next;
} process;

void add_process(process **head, int pid, int burst_time) {
    process *new_process = (process *)malloc(sizeof(process));
    new_process->pid = pid;
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = *head;
    *head = new_process;
}

void cpu_scheduling(process **head, int quantum) {
    process *current = NULL;
    process *next = NULL;

    clock_t start = clock();

    while (*head != NULL) {
        current = *head;

        if (current->remaining_time > 0) {
            sleep(1);
            current->remaining_time--;
        } else {
            if (current->next == NULL) {
                *head = current->next;
                free(current);
                continue;
            }

            next = current->next;
            *head = next;

            current->burst_time = current->burst_time - current->remaining_time;
            current->remaining_time = 0;

            add_process(head, current->pid, current->burst_time);
        }

        if (current->remaining_time == 0 && current->next != NULL) {
            next->remaining_time -= quantum;
            if (next->remaining_time <= 0) {
                next->remaining_time = 0;
                current->burst_time += next->burst_time;
                next->burst_time = 0;

                int total_waiting_time = clock() - start;
                double avg_waiting_time = (float)total_waiting_time / ((*head)->burst_time + next->burst_time + 1);

                printf("Process %d completed. Waiting time: %.6f\n", next->pid, avg_waiting_time);

                next = next->next;
                free(current);
                current = next;
            }
        }
    }
}

int main() {
    process *head = NULL;

    add_process(&head, 1, 10);
    add_process(&head, 2, 7);
    add_process(&head, 3, 5);

    int quantum = 2;

    cpu_scheduling(&head, quantum);

    return 0;
}