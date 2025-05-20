//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 100

typedef struct Process {
    char name[20];
    int priority;
    int state;
    struct Process* next;
} Process;

Process* head = NULL;

void schedule_process(Process* process) {
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void run_processes() {
    Process* current_process = head;
    while (current_process) {
        switch (current_process->state) {
            case 0:
                fork();
                current_process->state = 1;
                break;
            case 1:
                wait(NULL);
                current_process->state = 2;
                break;
            case 2:
                printf("Process %s completed.\n", current_process->name);
                current_process = current_process->next;
                break;
        }
    }
}

int main() {
    int i;
    Process* process = NULL;
    for (i = 0; i < MAX_PROCESSES; i++) {
        process = malloc(sizeof(Process));
        process->name[0] = 'a' + i;
        process->priority = i;
        process->state = 0;
        schedule_process(process);
    }

    run_processes();

    return 0;
}