//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct process* next;
};

void insert_process(struct process** head, int id, int arrival_time, int burst_time) {
    struct process* new_process = (struct process*)malloc(sizeof(struct process));
    new_process->id = id;
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

void round_robin(struct process** head) {
    int time_quantum = 5;
    struct process* current_process = NULL;
    struct process* next_process = NULL;

    while (!(*head)->remaining_time) {
        if (current_process == NULL) {
            current_process = (*head);
        } else {
            current_process->remaining_time -= time_quantum;
            if (current_process->remaining_time == 0) {
                next_process = current_process->next;
                current_process->next = NULL;
                insert_process(head, next_process->id, next_process->arrival_time, next_process->burst_time);
                current_process = NULL;
            } else {
                current_process = next_process;
            }
        }
        time_quantum--;
    }
}

int main() {
    struct process* head = NULL;
    insert_process(&head, 1, 0, 8);
    insert_process(&head, 2, 2, 4);
    insert_process(&head, 3, 4, 6);
    insert_process(&head, 4, 6, 2);
    insert_process(&head, 5, 8, 3);

    round_robin(&head);

    printf("Process completion order:\n");
    struct process* current_process = head;
    while (current_process) {
        printf("Process %d completed at time %d\n", current_process->id, current_process->arrival_time + current_process->burst_time);
        current_process = current_process->next;
    }

    return 0;
}