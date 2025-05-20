//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

typedef struct Process {
    char name[20];
    int priority;
    int state;
    struct Process* next;
} Process;

Process* head = NULL;

void addProcess(char* name, int priority) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->priority = priority;
    newProcess->state = 0;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newProcess;
    }
}

void schedule() {
    Process* currentProcess = head;
    int highestPriority = -1;

    for (Process* process = head; process; process = process->next) {
        if (process->state == 0 && process->priority > highestPriority) {
            highestPriority = process->priority;
            currentProcess = process;
        }
    }

    if (currentProcess) {
        currentProcess->state = 1;
        printf("Process: %s, State: Running\n", currentProcess->name);
    } else {
        printf("No processes to schedule\n");
    }
}

int main() {
    addProcess("A", 3);
    addProcess("B", 2);
    addProcess("C", 1);
    addProcess("D", 4);

    schedule();

    return 0;
}