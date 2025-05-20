//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    struct process* next;
};

void simulate_cpu(struct process* head) {
    time_t start_time = time(NULL);
    struct process* current = head;
    while (current) {
        int remaining_time = current->burst_time;
        while (remaining_time > 0) {
            sleep(1);
            remaining_time--;
        }
        current->waiting_time++;
        current->turn_around_time = time(NULL) - start_time;
        current = current->next;
    }
}

int main() {
    struct process* head = NULL;
    for (int i = 0; i < MAX_PROCESS; i++) {
        struct process* new_process = (struct process*)malloc(sizeof(struct process));
        new_process->id = i + 1;
        new_process->burst_time = rand() % 5;
        new_process->waiting_time = 0;
        new_process->turn_around_time = 0;
        new_process->next = head;
        head = new_process;
    }

    simulate_cpu(head);

    printf("Process ID\tWaiting Time\tTurnaround Time\n");
    for (struct process* current = head; current; current++) {
        printf("%d\t\t%d\t\t%d\n", current->id, current->waiting_time, current->turn_around_time);
    }

    return 0;
}