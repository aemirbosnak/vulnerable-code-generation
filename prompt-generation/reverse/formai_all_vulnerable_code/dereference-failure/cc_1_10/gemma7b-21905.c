//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(char* name, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    strcpy(process->name, name);
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, char* name, int burst_time) {
    Process* process = createProcess(name, burst_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t start_time = time(NULL);
    Process* current_process = head;
    while (current_process) {
        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        printf("Process: %s, Time spent: %d\n", current_process->name, time_spent);
        current_process->remaining_time -= time_spent;
        if (current_process->remaining_time == 0) {
            printf("Process: %s completed.\n", current_process->name);
            free(current_process);
            current_process = head;
        } else {
            current_process = current_process->next;
            start_time = time(NULL);
        }
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, "A", 5);
    addProcess(head, "B", 3);
    addProcess(head, "C", 8);
    addProcess(head, "D", 2);
    addProcess(head, "E", 4);

    roundRobin(head);

    return 0;
}