//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    char name[20];
    int cpu_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(char* name, int cpu_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->cpu_time = cpu_time;
    newProcess->waiting_time = 0;
    newProcess->turnaround_time = 0;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newProcess;
    }
}

void schedule() {
    Process* currentProcess = head;
    while (currentProcess) {
        currentProcess->waiting_time++;
        printf("%s is waiting for its turn...\n", currentProcess->name);
        sleep(1);
        currentProcess->waiting_time--;
        currentProcess->turnaround_time++;
        printf("%s has completed its turn!\n", currentProcess->name);
        currentProcess = currentProcess->next;
    }
}

int main() {
    insertProcess("Process A", 5);
    insertProcess("Process B", 3);
    insertProcess("Process C", 2);
    insertProcess("Process D", 4);

    schedule();

    return 0;
}