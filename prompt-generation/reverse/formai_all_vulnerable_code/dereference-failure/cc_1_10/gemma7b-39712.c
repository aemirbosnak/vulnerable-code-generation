//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process {
    int pid;
    char name[20];
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

Process* createProcess(int pid, char* name, int burstTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->pid = pid;
    strcpy(process->name, name);
    process->burstTime = burstTime;
    process->remainingTime = burstTime;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int pid, char* name, int burstTime) {
    Process* process = createProcess(pid, name, burstTime);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t start, end;
    int quantum = 5;
    start = time(NULL);
    while (head) {
        end = time(NULL);
        if (end - start >= quantum) {
            head->remainingTime--;
            start = time(NULL);
        }
        printf("Process ID: %d, Remaining Time: %d\n", head->pid, head->remainingTime);
        head = head->next;
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, "Process A", 10);
    addProcess(head, 2, "Process B", 8);
    addProcess(head, 3, "Process C", 6);
    addProcess(head, 4, "Process D", 4);
    addProcess(head, 5, "Process E", 2);

    roundRobin(head);

    return 0;
}