//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    struct Process* next;
} Process;

Process* createProcess(int process_id, int arrival_time, int burst_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = process_id;
    newProcess->arrival_time = arrival_time;
    newProcess->burst_time = burst_time;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(Process* head, int process_id, int arrival_time, int burst_time) {
    Process* newProcess = createProcess(process_id, arrival_time, burst_time);
    if (head == NULL) {
        head = newProcess;
    } else {
        newProcess->next = head;
        head = newProcess;
    }
}

void simulate(Process* head) {
    int time = 0;
    while (head) {
        if (head->arrival_time == time) {
            printf("Process %d arrived.\n", head->process_id);
            time += head->burst_time;
            printf("Process %d completed.\n", head->process_id);
            free(head);
            head = head->next;
        } else {
            time++;
        }
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 0, 5);
    addProcess(head, 2, 2, 4);
    addProcess(head, 3, 1, 3);
    addProcess(head, 4, 3, 2);
    simulate(head);
    return 0;
}