//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_NAME_LENGTH 20

typedef struct {
    int pid;
    char name[MAX_NAME_LENGTH];
    int status;
} process;

int num_processes = 0;
process *processes = NULL;

void add_process(int pid, char *name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum number of processes reached.\n");
        return;
    }

    process *new_process = (process *) malloc(sizeof(process));
    new_process->pid = pid;
    strcpy(new_process->name, name);
    new_process->status = 0;

    processes = (process *) realloc(processes, sizeof(process) * (num_processes + 1));
    processes[num_processes] = *new_process;
    num_processes++;
}

void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            free(processes[i].name);
            processes = (process *) realloc(processes, sizeof(process) * (num_processes - 1));
            memmove(&processes[i], &processes[i+1], sizeof(process) * (num_processes - i - 1));
            num_processes--;
            break;
        }
    }
}

void update_process_status(int pid, int status) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = status;
            break;
        }
    }
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%d - %s (%d)\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    add_process(1, "init");
    add_process(2, "login");
    add_process(3, "shell");

    print_processes();

    remove_process(2);

    print_processes();

    update_process_status(1, 1);

    print_processes();

    return 0;
}