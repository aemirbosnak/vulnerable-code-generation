//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

void insertProcess(Process** head, int process_id, char* name, int burst_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = process_id;
    strcpy(newProcess->name, name);
    newProcess->burst_time = burst_time;
    newProcess->waiting_time = 0;
    newProcess->turnaround_time = 0;
    newProcess->next = NULL;

    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*head)->next = newProcess;
    }
}

void roundRobin(Process** head) {
    int i = 0;
    Process* currentProcess = *head;
    while (currentProcess) {
        currentProcess->waiting_time++;
        i++;
        if (i == MAX_QUEUE_SIZE) {
            currentProcess = *head;
            i = 0;
        }
        currentProcess = currentProcess->next;
    }
}

void calculateTurnaroundTime(Process** head) {
    Process* currentProcess = *head;
    while (currentProcess) {
        currentProcess->turnaround_time = currentProcess->waiting_time + currentProcess->burst_time;
        currentProcess = currentProcess->next;
    }
}

int main() {
    Process* head = NULL;
    insertProcess(&head, 1, "Process A", 5);
    insertProcess(&head, 2, "Process B", 3);
    insertProcess(&head, 3, "Process C", 8);
    insertProcess(&head, 4, "Process D", 2);
    insertProcess(&head, 5, "Process E", 4);

    roundRobin(&head);
    calculateTurnaroundTime(&head);

    printf("Process ID\tName\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("------------------------------------------------------------------------\n");
    for (Process* currentProcess = head; currentProcess; currentProcess = currentProcess->next) {
        printf("%d\t%s\t%d\t%d\t%d\n", currentProcess->process_id, currentProcess->name, currentProcess->burst_time, currentProcess->waiting_time, currentProcess->turnaround_time);
    }

    return 0;
}