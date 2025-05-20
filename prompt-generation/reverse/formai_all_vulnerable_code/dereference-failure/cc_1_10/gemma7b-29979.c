//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(int id, int arrivalTime, int serviceTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = id;
    newProcess->arrival_time = arrivalTime;
    newProcess->service_time = serviceTime;
    newProcess->completion_time = 0;
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

void simulate() {
    Process* currentProcess = head;
    while (currentProcess) {
        int time = currentProcess->arrival_time;
        currentProcess->completion_time = time + currentProcess->service_time;
        currentProcess = currentProcess->next;
    }
}

int main() {
    insertProcess(1, 0, 5);
    insertProcess(2, 2, 4);
    insertProcess(3, 4, 3);
    insertProcess(4, 6, 2);

    simulate();

    Process* process = head;
    while (process) {
        printf("Process ID: %d, Arrival Time: %d, Service Time: %d, Completion Time: %d\n", process->process_id, process->arrival_time, process->service_time, process->completion_time);
        process = process->next;
    }

    return 0;
}