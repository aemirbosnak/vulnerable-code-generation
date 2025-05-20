//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_INSTRUCTIONS 10

typedef struct Process {
    int number;
    int instructions;
    struct Process* next;
} Process;

Process* head = NULL;

void schedule() {
    time_t start_time = time(NULL);
    Process* current = head;
    int i = 0;

    printf("Process %d is running...\n", current->number);

    for (i = 0; i < current->instructions; i++) {
        printf("Instruction %d: %s\n", i + 1, current->instructions);
        sleep(1);
    }

    time_t end_time = time(NULL);
    int execution_time = end_time - start_time;

    printf("Process %d completed in %d seconds\n", current->number, execution_time);
    current = current->next;
}

void addProcess(int number, int instructions) {
    Process* newProcess = malloc(sizeof(Process));
    newProcess->number = number;
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
    addProcess(3, MAX_INSTRUCTIONS / 2);
    addProcess(4, MAX_INSTRUCTIONS / 4);
    addProcess(5, MAX_INSTRUCTIONS / 8);

    schedule();

    return 0;
}