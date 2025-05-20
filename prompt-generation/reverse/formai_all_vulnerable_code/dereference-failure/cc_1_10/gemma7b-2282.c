//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_INSTRUCTIONS 10

typedef struct Process {
    int id;
    int instructions;
    struct Process* next;
} Process;

Process* head = NULL;

void schedule() {
    Process* current = head;
    while (current) {
        printf("Process %d is running...\n", current->id);
        current->instructions--;
        if (current->instructions == 0) {
            Process* next = current->next;
            free(current);
            current = next;
        }
    }
}

void addProcess(int id, int instructions) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->instructions = instructions;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* lastProcess = head;
        while (lastProcess->next) {
            lastProcess = lastProcess->next;
        }
        lastProcess->next = newProcess;
    }
}

int main() {
    addProcess(1, MAX_INSTRUCTIONS);
    addProcess(2, MAX_INSTRUCTIONS - 1);
    addProcess(3, MAX_INSTRUCTIONS - 2);
    addProcess(4, MAX_INSTRUCTIONS - 3);
    addProcess(5, MAX_INSTRUCTIONS - 4);

    schedule();

    return 0;
}