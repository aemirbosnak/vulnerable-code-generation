//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int id;
    int burstTime;
    int waitingTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int burstTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->burstTime = burstTime;
    process->waitingTime = 0;
    process->next = NULL;

    return process;
}

void addProcess(Process* head, int id, int burstTime) {
    Process* process = createProcess(id, burstTime);

    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t start = time(NULL);

    while (head) {
        int remainingTime = head->burstTime - head->waitingTime;

        if (remainingTime > 0) {
            head->waitingTime++;
            sleep(1);
        } else {
            head->waitingTime = 0;
            printf("Process %d finished.\n", head->id);
            head = head->next;
        }
    }

    time_t end = time(NULL);
    printf("Total time: %ld seconds.\n", end - start);
}

int main() {
    Process* head = NULL;

    addProcess(head, 1, 5);
    addProcess(head, 2, 3);
    addProcess(head, 3, 6);
    addProcess(head, 4, 2);
    addProcess(head, 5, 4);

    roundRobin(head);

    return 0;
}