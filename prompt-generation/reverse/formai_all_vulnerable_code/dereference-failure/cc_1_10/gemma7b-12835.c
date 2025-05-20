//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int process_id;
    char name[20];
    int cpu_burst_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

Process* head = NULL;

void addProcess(int id, char* name, int cpu_burst_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = id;
    strcpy(newProcess->name, name);
    newProcess->cpu_burst_time = cpu_burst_time;
    newProcess->waiting_time = 0;
    newProcess->turnaround_time = 0;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProcess;
    }
}

void roundRobin() {
    Process* currentProcess = head;
    while (currentProcess) {
        printf("Process ID: %d, Name: %s, CPU Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", currentProcess->process_id, currentProcess->name, currentProcess->cpu_burst_time, currentProcess->waiting_time, currentProcess->turnaround_time);
        currentProcess->waiting_time++;
        currentProcess = currentProcess->next;
    }
}

int main() {
    addProcess(1, "Process A", 5);
    addProcess(2, "Process B", 3);
    addProcess(3, "Process C", 7);
    addProcess(4, "Process D", 2);

    roundRobin();

    return 0;
}