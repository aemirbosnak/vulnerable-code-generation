//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PROC_NUM 10

typedef struct Process {
    char name[20];
    int pid;
    struct Process* next;
} Process;

Process* head = NULL;

void monitor() {
    Process* current = head;
    while (current) {
        printf("Process: %s, PID: %d, CPU Usage: %f%%\n", current->name, current->pid, (double)rand() / RAND_MAX);
        sleep(1);
        current = current->next;
    }
}

void addProcess(char* name, int pid) {
    Process* newProcess = malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->pid = pid;
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
    addProcess("firefox", 1234);
    addProcess("chrome", 5678);
    addProcess("vscode", 9123);

    monitor();

    return 0;
}