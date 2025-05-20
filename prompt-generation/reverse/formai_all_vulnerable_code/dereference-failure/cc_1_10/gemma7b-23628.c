//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME 100

typedef struct process {
    int id;
    int arrivalTime;
    int executionTime;
    struct process* next;
} process;

process* createProcess(int id, int arrivalTime, int executionTime) {
    process* newProcess = (process*)malloc(sizeof(process));
    newProcess->id = id;
    newProcess->arrivalTime = arrivalTime;
    newProcess->executionTime = executionTime;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(process* head, process* newProcess) {
    if (head == NULL) {
        head = newProcess;
    } else {
        head->next = newProcess;
        head = newProcess;
    }
}

void schedule(process* head) {
    time_t currentTime = time(NULL);
    process* currentProcess = NULL;

    while (head) {
        if (currentProcess == NULL || currentTime >= head->arrivalTime) {
            currentProcess = head;
            head = head->next;
        } else {
            sleep(1);
        }
    }

    printf("All processes completed.\n");
}

int main() {
    process* head = NULL;

    // Create some processes
    process* process1 = createProcess(1, 0, 20);
    process* process2 = createProcess(2, 10, 30);
    process* process3 = createProcess(3, 20, 40);
    process* process4 = createProcess(4, 30, 50);

    // Add processes to the schedule
    addProcess(head, process1);
    addProcess(head, process2);
    addProcess(head, process3);
    addProcess(head, process4);

    // Schedule the processes
    schedule(head);

    return 0;
}