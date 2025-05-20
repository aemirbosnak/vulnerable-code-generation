//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define MAX_QUEUE 10

typedef struct process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(int pid, char* name, int burst_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->pid = pid;
    strcpy(new_process->name, name);
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;
    return new_process;
}

void add_process(process* head, int pid, char* name, int burst_time) {
    process* new_process = create_process(pid, name, burst_time);
    if (head == NULL) {
        head = new_process;
    } else {
        head->next = new_process;
        head = new_process;
    }
}

void round_robin(process* head) {
    int quantum = 5;
    process* current_process = head;
    while (current_process) {
        printf("Process: %s, Remaining Time: %d\n", current_process->name, current_process->remaining_time);
        current_process->remaining_time -= quantum;
        if (current_process->remaining_time == 0) {
            printf("Process: %s completed.\n", current_process->name);
            free(current_process);
            current_process = head;
        } else {
            current_process = current_process->next;
        }
    }
}

int main() {
    process* head = NULL;
    add_process(head, 1, "A", 8);
    add_process(head, 2, "B", 10);
    add_process(head, 3, "C", 6);
    add_process(head, 4, "D", 4);
    add_process(head, 5, "E", 2);

    round_robin(head);

    return 0;
}