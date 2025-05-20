//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROC 5
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int pid, char* name, int burst_time) {
    Process* process = malloc(sizeof(Process));
    process->pid = pid;
    strcpy(process->name, name);
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int pid, char* name, int burst_time) {
    Process* process = createProcess(pid, name, burst_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t start_time = time(NULL);
    Process* current = head;
    while (current) {
        current->remaining_time--;
        if (current->remaining_time == 0) {
            printf("Process %d completed.\n", current->pid);
            free(current);
            current = head;
        } else {
            current = current->next;
        }
    }
    time_t end_time = time(NULL);
    printf("Total time taken: %.2f seconds.\n", (double)(end_time - start_time));
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, "Process A", 5);
    addProcess(head, 2, "Process B", 8);
    addProcess(head, 3, "Process C", 3);
    addProcess(head, 4, "Process D", 4);
    addProcess(head, 5, "Process E", 6);

    roundRobin(head);

    return 0;
}