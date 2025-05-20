//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define MAX_NAME_LENGTH 32
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    int pid;
    char name[MAX_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
} process_t;

int num_processes = 0;
process_t *processes = NULL;

void add_process(int pid, char *name, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_t *new_process = (process_t *) malloc(sizeof(process_t));
    new_process->pid = pid;
    strncpy(new_process->name, name, MAX_NAME_LENGTH);
    strncpy(new_process->command, command, MAX_COMMAND_LENGTH);

    processes = (process_t *) realloc(processes, sizeof(process_t) * (num_processes + 1));
    processes[num_processes] = *new_process;
    num_processes++;
}

void remove_process(int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes = (process_t *) realloc(processes, sizeof(process_t) * (num_processes - 1));
            num_processes--;
            return;
        }
    }
}

void print_processes() {
    printf("PID\tName\tCommand\n");
    int i;
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%s\n", processes[i].pid, processes[i].name, processes[i].command);
    }
}

int main() {
    add_process(1, "init", "init");
    add_process(1234, "my_process", "my_command");

    print_processes();

    remove_process(1234);

    print_processes();

    return 0;
}