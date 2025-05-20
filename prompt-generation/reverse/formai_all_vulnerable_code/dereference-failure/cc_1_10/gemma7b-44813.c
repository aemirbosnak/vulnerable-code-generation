//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 20

typedef struct Process {
    int id;
    char name[20];
    int burst_time;
    int waiting_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int id, char* name, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    strcpy(process->name, name);
    process->burst_time = burst_time;
    process->waiting_time = 0;
    process->remaining_time = burst_time;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int id, char* name, int burst_time) {
    Process* process = createProcess(id, name, burst_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t start_time = time(NULL);
    int current_process = 0;
    while (head) {
        Process* process = head->next;
        if (process) {
            process->waiting_time++;
            head = process;
        } else {
            head = process;
            current_process = 0;
        }
        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        printf("Process %d spent %d seconds waiting.\n", process->id, time_spent);
        start_time = end_time;
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, "Alice", 5);
    addProcess(head, 2, "Bob", 8);
    addProcess(head, 3, "Charlie", 3);
    addProcess(head, 4, "Dave", 2);

    roundRobin(head);

    return 0;
}