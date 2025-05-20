//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct process {
    int id;
    int burst_time;
    struct process* next;
} process;

process* create_process(int id, int burst_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->id = id;
    new_process->burst_time = burst_time;
    new_process->next = NULL;
    return new_process;
}

void add_process(process* head, int id, int burst_time) {
    process* new_process = create_process(id, burst_time);
    if (head == NULL) {
        head = new_process;
    } else {
        new_process->next = head;
        head = new_process;
    }
}

void round_robin(process* head) {
    time_t start_time = time(NULL);
    process* current_process = head;
    while (current_process) {
        int remaining_time = current_process->burst_time - (time(NULL) - start_time);
        if (remaining_time > 0) {
            printf("Process %d is running...\n", current_process->id);
            sleep(remaining_time);
        } else {
            printf("Process %d is completed.\n", current_process->id);
            free(current_process);
            current_process = head;
        }
    }
}

int main() {
    process* head = NULL;
    add_process(head, 1, 5);
    add_process(head, 2, 3);
    add_process(head, 3, 2);
    add_process(head, 4, 4);
    round_robin(head);
    return 0;
}