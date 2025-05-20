//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct Process {
    char name[20];
    int priority;
    int state;
    struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(char* name, int priority) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->priority = priority;
    newProcess->state = 0;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* currentProcess = head;
        while (currentProcess->next != NULL) {
            currentProcess = currentProcess->next;
        }
        currentProcess->next = newProcess;
    }
}

void schedule() {
    Process* currentProcess = head;
    while (currentProcess->next != NULL) {
        int currentProcessPriority = currentProcess->priority;
        int nextProcessPriority = currentProcess->next->priority;

        if (currentProcessPriority < nextProcessPriority) {
            currentProcess = currentProcess->next;
        } else {
            currentProcess->state = 1;
            printf("%s is running\n", currentProcess->name);
            sleep(1);
            currentProcess->state = 0;
            printf("%s is waiting\n", currentProcess->name);
        }
    }
}

int main() {
    insertProcess("Process A", 5);
    insertProcess("Process B", 3);
    insertProcess("Process C", 7);
    insertProcess("Process D", 2);

    schedule();

    return 0;
}