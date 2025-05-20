//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 20

typedef struct Process {
    char name[20];
    int priority;
    int state;
    struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(char* name, int priority) {
    Process* newProcess = malloc(sizeof(Process));
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

void scheduleProcess() {
    Process* currentProcess = head;
    int i = 0;
    while (currentProcess) {
        printf("%d. %s (Priority: %d)\n", i++, currentProcess->name);
        currentProcess = currentProcess->next;
    }
}

int main() {
    insertProcess("Process A", 5);
    insertProcess("Process B", 3);
    insertProcess("Process C", 2);
    insertProcess("Process D", 4);

    scheduleProcess();

    return 0;
}